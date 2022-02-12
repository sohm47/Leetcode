class Solution {
    // Time: O(N), Space: O(1)
    public int removeElement(int[] nums, int val) {
        int left=0, right=nums.length;
        while(left < right) {
            if(nums[left] == val) {
                nums[left] = nums[right-1];
                right -= 1;
            }
            else {
                left += 1;
            }
        }
        
        return left;
    }
}
