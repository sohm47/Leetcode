class Solution {
    // Time: O(N^3)
    // Space: O(1)
    public List<List<Integer>> fourSum(int[] nums, int target) {
        if(nums.length < 4)
            return new ArrayList<>();
        
        Arrays.sort(nums);
        
        List<List<Integer>> quadruplets = new ArrayList<>();
        for(int i=0; i<nums.length; i++) {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            
            for(int j=i+1; j<nums.length; j++) {
                if(j != i+1 && nums[j] == nums[j-1])
                    continue;
                
                int left = j+1, right = nums.length-1, sum = target-(nums[i]+nums[j]);
                while(left < right) {
                    if((left != j+1 && nums[left] == nums[left-1]) || (nums[left] + nums[right] < sum))
                        left += 1;
                    else if((right != nums.length-1 && nums[right] == nums[right+1]) || (nums[left] + nums[right] > sum))
                        right -= 1;
                    else {
                        quadruplets.add(new ArrayList<Integer>(Arrays.asList(nums[i], nums[j], nums[left], nums[right])));
                        left += 1;
                        right -= 1;
                    }
                }
            }
        }
        
        return quadruplets;
    }
}
