class Solution {
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    // Time: O(N)
    // Space: O(N)
    public int[] sortArrayByParity(int[] nums) {
        int left = 0, right = nums.length-1;
        while(left < right) {
            if(nums[left]%2 > nums[right]%2)
                swap(nums, left, right);
            
            if(nums[left]%2 == 0)
                left += 1;
            if(nums[right]%2 != 0)
                right -= 1; 
        }
        
        return nums;
    }
}
