class Solution {
    // Time: O(N^2), Space: O(1)
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        
        List<List<Integer>> triplets = new ArrayList<>();
        
        for(int i=0; i<nums.length; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int j=i+1, k=nums.length-1;
            while(j < k) {                
                if(nums[j]+nums[k] == -nums[i]) {
                    triplets.add(new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[k])));
                    j += 1;
                    k -= 1;
                    
                    while(j < k && nums[j] == nums[j-1])
                        j += 1;
                    while(j < k && k != nums.length-1 && nums[k] == nums[k+1])
                        k -= 1;
                }
                else if(nums[j]+nums[k] > -nums[i]) {
                    k -= 1;
                }
                else {
                    j += 1;
                }
            }
        }
        
        return triplets;
    }
}
