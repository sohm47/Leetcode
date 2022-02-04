class Solution {
    // Time: O(N), Space: O(1)
    public int removeDuplicates(int[] nums) {
        if(nums.length < 2) {
            return nums.length;
        }
        
        int unique = 1;
        for(int i=1; i<nums.length; i++) {
            if(nums[i] != nums[i-1]) {
                nums[unique++] = nums[i];
            }
        }
        
        return unique;
        
    }
}
