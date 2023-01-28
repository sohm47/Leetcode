class Solution {
    // Time: O(N), Space: O(1)
    public int pivotIndex(int[] nums) {
        int totalSum = 0;
        for(int i=0; i<nums.length; i++) {
            totalSum += nums[i];
        }

        int currentSum = 0;
        for(int i=0; i<nums.length; i++) {
            if(totalSum-nums[i] == currentSum*2) {
                return i;
            }
            currentSum += nums[i];
        }

        return -1;
    }
}
