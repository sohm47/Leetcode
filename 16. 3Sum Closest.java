class Solution {
    // Time: O(N^2), Space: O(1)
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        
        int closestSum = nums[0] + nums[1] + nums[nums.length-1];
        
        for(int i=0; i<nums.length; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j=i+1, k=nums.length-1;
            while(j < k) {
                if(j > i+1 && nums[j] == nums[j-1]) {
                    j += 1;
                    continue;
                }
                if(k<nums.length-1 && nums[k] == nums[k+1]) {
                    k -= 1;
                    continue;
                }
                
                int tempSum = nums[i]+nums[j]+nums[k];
                if(Math.abs(tempSum-target) < Math.abs(closestSum-target)) {
                    closestSum = tempSum;
                }
                
                if(tempSum-target < 0) {
                    j += 1;
                }
                else {
                    k -= 1;
                }
            }
        }
        
        return closestSum;
    }
}
