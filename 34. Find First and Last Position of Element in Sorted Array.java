class Solution {
    int getLowerRange(int[] nums, int target) {
        int low=0, high=nums.length-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
               low = mid + 1; 
            }
        }
        
        return low;
    }
    
    //  Time: O(LogN), Space: O(1)
    public int[] searchRange(int[] nums, int target) {
        int lower = getLowerRange(nums, target);
        if (lower != nums.length && nums[lower] == target) {
            int higher = getLowerRange(nums, target+1) - 1;
            return new int[]{lower, higher};
        }
            
        return new int[]{-1, -1};
    }
}
