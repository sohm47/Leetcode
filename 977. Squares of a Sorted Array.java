class Solution {
    // Time: O(N), Space: O(N)
    public int[] sortedSquares(int[] nums) {
        int sortedArray[] = new int[nums.length];
        int left=0, right=nums.length-1, currentIndex=nums.length;
        while(left <= right) {
            if(nums[left]*nums[left] < nums[right]*nums[right]) {
                sortedArray[--currentIndex] = nums[right]*nums[right];
                --right;
            } else {
                sortedArray[--currentIndex] = nums[left]*nums[left];
                ++left;
            }
        }

        return sortedArray;
    }
}
