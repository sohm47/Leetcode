class Solution {
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    // Time: O(N)
    // Space: O(1)
    public int[] sortArrayByParityII(int[] nums) {
        int evenPointer = 0, oddPointer = 1;
        while(evenPointer < nums.length && oddPointer < nums.length) {
            if(nums[evenPointer]%2 > nums[oddPointer]%2)
                swap(nums, evenPointer, oddPointer);
            
            if(nums[evenPointer]%2 == 0)
                evenPointer += 2;
            if(nums[oddPointer]%2 != 0)
                oddPointer += 2;
        }
        
        return nums;
    }
}
