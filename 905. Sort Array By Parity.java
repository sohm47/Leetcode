class Solution {
    // Time: O(N)
    // Space: O(1)
    public int[] sortArrayByParity(int[] nums) {
        int slowPointer = 0, fastPointer = 0;
        while(fastPointer < nums.length) {
            if(nums[fastPointer]%2 == 0) {
                int temp = nums[slowPointer];
                nums[slowPointer] = nums[fastPointer];
                nums[fastPointer] = temp;
                slowPointer += 1;
            }
            fastPointer += 1;
        }
        
        return nums;
    }
}
