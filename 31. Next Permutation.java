class Solution {
    private void swapNumbers(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    // Time: O(N), Space: O(1)
    public void nextPermutation(int[] nums) {
        int i = nums.length-2;
        while(i > -1 && nums[i] >= nums[i+1]) {
            i -= 1;
        }
        
        if(i != -1) {
            int j = nums.length-1;
            while(j > i && nums[j] <= nums[i]) {
                j -=1;
            }
            swapNumbers(nums, i, j);
        }
        i += 1;
        
        int j = nums.length-1;
        while(i < j) {
            swapNumbers(nums, i, j);
            i += 1;
            j -= 1;
        }
    }
}
