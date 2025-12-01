// --- Global State and DOM Elements ---
let walkthroughSteps = [];
let currentStepIndex = 0;

const outputDiv = document.getElementById('output');
const initialSetupDiv = document.getElementById('initialSetup');
const arrayVizDiv = document.getElementById('arrayViz');
const stepCounterDiv = document.getElementById('stepCounter');
const stepInfoDiv = document.getElementById('stepInfo');
const prevButton = document.getElementById('prevButton');
const nextButton = document.getElementById('nextButton');
const runButton = document.getElementById('runButton');
const numsInput = document.getElementById('numsInput');
const pInput = document.getElementById('pInput');


// --- Core Algorithm Logic ---

/**
 * Calculates the walkthrough steps for the minSubarray problem.
 * @param {number[]} nums 
 * @param {number} p 
 * @returns {object[]} Array of step objects.
 */
function calculateWalkthrough(nums, p) {
    const n = nums.length;
    
    // Step 1: Calculate total sum and target remainder
    let totalSum = 0;
    for (const num of nums) {
        totalSum = (totalSum + num) % p;
    }
    const target = totalSum % p;
    
    const steps = [];

    // Initial State
    steps.push({
        type: 'SETUP',
        target: target,
        initialMinLen: n,
        currentSum: 0,
        modMap: new Map([[0, -1]]),
        minLen: n,
        result: target === 0 ? 0 : null,
        p: p // Store p in setup for easy access in templates
    });

    if (target === 0) {
        steps[0].message = "Target is 0. The total sum is already divisible by p. Result is 0.";
        return steps;
    }

    // Step 2: Initialize map and variables
    let modMap = new Map([[0, -1]]); // Stores (prefix_sum % p, index)
    let currentSum = 0;
    let minLen = n;

    // Step 3: Iterate
    for (let i = 0; i < n; ++i) {
        const num = nums[i];

        // Update current prefix sum mod p
        currentSum = (currentSum + num) % p;

        // Calculate 'needed' remainder for a match
        const needed = (currentSum - target + p) % p;

        let step = {
            type: 'ITERATION',
            index: i,
            num: num,
            currentSum: currentSum,
            target: target,
            needed: needed,
            found: false,
            foundIndex: null,
            newMinLen: null,
            minLen: minLen,
            modMap: new Map(modMap), // Clone map for state preservation
            p: p // Store p for access during rendering
        };

        // Check if 'needed' remainder has been seen
        if (modMap.has(needed)) {
            step.found = true;
            const j_index = modMap.get(needed);
            step.foundIndex = j_index;
            
            // Length is i - j_index
            const length = i - j_index;
            
            if (length < minLen) {
                minLen = length;
                step.newMinLen = minLen;
            }
        }
        
        // Store the current remainder and index
        modMap.set(currentSum, i);
        step.nextModMap = new Map(modMap); // Clone map after update
        step.minLen = minLen; // Store final minLen for this step

        steps.push(step);
    }

    // Final Result State
    steps.push({
        type: 'FINAL',
        minLen: minLen,
        n: n,
        result: minLen === n ? -1 : minLen,
        p: p
    });

    return steps;
}


// --- KaTeX Helper Function ---

// Corrected mapToHtml structure for reliable KaTeX rendering
function mapToHtml(map) {
    let parts = [];
    map.forEach((value, key) => {
        let displayValue = value;
        if (value === -1 || value === Number.MAX_SAFE_INTEGER) {
            displayValue = '-1'; 
        }
        // Simplified KaTeX syntax: {key : value}
        // Use single backslash for KaTeX commands like \{
        parts.push(`\\{${key} : ${displayValue}\\}`); 
    });
    
    // Output using display math ($$)$$
    // Note: We use the array structure and escape the outer braces.
    return `<div class="mod-map-display">$$\\{${parts.join(', ')}\\}$$</div>`;
}

// Function to call KaTeX on dynamically generated content
function renderKaTeX() {
    if (window.renderMathInElement) {
         renderMathInElement(outputDiv, {
            delimiters: [
                {left: "$$", right: "$$", display: true},
                {left: "$", right: "$", display: false},
                {left: "\\[", right: "\\]", display: true},
                {left: "\\(", right: "\\)", display: false}
            ]
        });
    }
}


// --- UI Rendering Logic ---

function renderStep(nums, p) {
    if (walkthroughSteps.length === 0) return;

    const step = walkthroughSteps[currentStepIndex];
    const originalNums = numsInput.value.split(',').map(s => s.trim());
    const n = originalNums.length;

    stepCounterDiv.innerHTML = `<h3>Step ${currentStepIndex} of ${walkthroughSteps.length - 1}</h3>`;
    arrayVizDiv.innerHTML = '';
    stepInfoDiv.innerHTML = '';
    initialSetupDiv.innerHTML = ''; // Clear setup on every step except 0
    
    // Update button states
    prevButton.disabled = currentStepIndex === 0;
    nextButton.disabled = currentStepIndex === walkthroughSteps.length - 1;

    // --- SETUP Step (Index 0) ---
    if (step.type === 'SETUP') {
        initialSetupDiv.innerHTML = `
            <p>Array $\\text{nums}$: [${originalNums.join(', ')}]</p>
            <p>Divisor $p$: <span class="highlight">${step.p}</span></p>
            <p>Total Sum $\\pmod p$: $\\text{target} = \\text{TotalSum} \\pmod p = <span class="highlight">${step.target}</span>$</p>
            <p>Initial $\\text{minLen}$: $n = ${n}$</p>
            <p>Initial $\\text{modMap}$: ${mapToHtml(step.modMap)}</p>
        `;
        if (step.result === 0) {
            stepInfoDiv.innerHTML = `<h3>🎉 Result: 0 (Already divisible)</h3>`;
        } else {
            stepInfoDiv.innerHTML = `<h3>🔍 Starting Iteration: Looking for subarray sum $S_{sub} \\equiv ${step.target} \\pmod {${step.p}}$</h3>`;
        }
    } 
    
    // --- ITERATION Step ---
    else if (step.type === 'ITERATION') {
        const mapDisplay = mapToHtml(step.modMap);

        // Array Visualization
        const viz = originalNums.map((val, idx) => {
            const isCurrent = idx === step.index;
            return `<span class="${isCurrent ? 'current-element' : ''}">${val}</span>`;
        }).join('');
        arrayVizDiv.innerHTML = `<h4>Current Array State (i = ${step.index}):</h4><div class="array-display">${viz}</div>`;
        
        // Use local variable 'p' and ternary operators for maximum safety
        const p_safe = step.p || 0; // Use 0 as a safe fallback for p
        const target_safe = step.target || 0; // Use 0 as a safe fallback for target

        let details = `
            <p>Current Prefix Sum ($\\text{currentSum}_i \\pmod p$): <span class="highlight">${step.currentSum}</span></p>
            <p>Needed Remainder ($\\text{currentSum}_j \\pmod p$): $\\text{needed} = (\\text{currentSum}_i - \\text{target} + p) \\pmod p$</p>
            <p>Needed Remainder: $\\text{needed} = (${step.currentSum} - ${target_safe} + ${p_safe}) \\pmod {${p_safe}} = <span class="highlight">${step.needed}</span>$</p>
        `;

        if (step.found) {
            details += `
                <p>✅ Found $\\text{needed} = ${step.needed}$ in map at index $j = <span class="highlight">${step.foundIndex}</span>$</p>
                <p>Calculated Length: $i - j = ${step.index} - ${step.foundIndex} = <span class="highlight">${step.index - step.foundIndex}</span>$</p>
            `;
            if (step.newMinLen !== null) {
                details += `<p>✨ Updated $\\text{minLen}$ from ${walkthroughSteps[currentStepIndex-1].minLen} to <span class="highlight">${step.newMinLen}</span></p>`;
            } else {
                 details += `<p>Current $\\text{minLen}$ remains $\\text{minLen} = ${step.minLen}$</p>`;
            }
        } else {
            details += `<p>❌ $\\text{needed} = ${step.needed}$ not found in map. No match yet.</p>`;
        }
        
        details += `
            <h4>ModMap State:</h4>
            <p>Before Update: ${mapToHtml(step.modMap)}</p>
            <p>After Update ($\\text{modMap}[${step.currentSum}] = ${step.index}$): ${mapToHtml(step.nextModMap)}</p>
        `;
        
        stepInfoDiv.innerHTML = details;

    } 
    
    // --- FINAL Step ---
    else if (step.type === 'FINAL') {
        arrayVizDiv.innerHTML = '';
        initialSetupDiv.innerHTML = '';

        let resultMsg;
        if (step.result === -1) {
            resultMsg = "No valid subarray was found whose removal makes the remaining sum divisible by $p$.";
        } else {
            resultMsg = `The smallest subarray to remove has a length of ${step.result}$.`;
        }

        stepInfoDiv.innerHTML = `
            <h3>🏁 Final Result</h3>
            <p>Final $\\text{minLen}$: <span class="highlight">${step.minLen}</span></p>
            <p>Original Array Length ($n$): ${step.n}</p>
            <p>Final Answer: <span class="highlight">${step.result}</span></p>
            <p>${resultMsg}</p>
        `;
    }
    
    // Call KaTeX to process the new content
    renderKaTeX();
}


// --- Event Handlers ---

runButton.onclick = () => {
    try {
        const numsStr = numsInput.value.trim();
        const nums = numsStr.split(',').map(s => parseInt(s.trim())).filter(n => !isNaN(n));
        const p = parseInt(pInput.value);

        if (nums.length === 0 || isNaN(p) || p <= 0) {
            alert('Please enter a valid array of numbers and a positive divisor p.');
            return;
        }

        walkthroughSteps = calculateWalkthrough(nums, p);
        currentStepIndex = 0;
        
        // Pass the calculated p to the render function
        renderStep(nums, p); 
        
        prevButton.disabled = true;
        nextButton.disabled = walkthroughSteps.length <= 1;

    } catch (e) {
        console.error('Run Error:', e);
        alert('An error occurred during calculation. Check console for details.');
    }
};

prevButton.onclick = () => {
    if (currentStepIndex > 0) {
        currentStepIndex--;
        renderStep(); 
    }
};

nextButton.onclick = () => {
    if (currentStepIndex < walkthroughSteps.length - 1) {
        currentStepIndex++;
        renderStep(); 
    }
};

// Initialize the page with the default values and render LaTeX
runButton.click();