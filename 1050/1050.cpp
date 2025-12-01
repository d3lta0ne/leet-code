class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        
        int r = total % p;
        if (r == 0) return 0; // already divisible

        unordered_map<int, int> mp; 
        mp.reserve(nums.size());
        mp[0] = -1; // prefix before starting

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            prefix = (prefix + nums[i]) % p;

            // We want (prefix[i] - prefix[j]) % p = r
            int need = (prefix - r + p) % p;

            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            // store current prefix mod location
            mp[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
