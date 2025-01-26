class Solution {
    public int[] sortedSquares(int[] nums) {
        List<Integer> squaredList = new ArrayList<>();
        
        // Square each element and add to the list
        for (int num : nums) {
            squaredList.add(num * num);
        }
        
        // Sort the list
        Collections.sort(squaredList);
        
        // Convert the list back to an array
        int[] result = new int[squaredList.size()];
        for (int i = 0; i < squaredList.size(); i++) {
            result[i] = squaredList.get(i);
        }

        return result;
    }
}