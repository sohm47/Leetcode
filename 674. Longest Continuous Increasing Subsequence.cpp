class Solution {
public:
    // Time: O(N), Space: O(1)
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int longest = 1, count = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]>nums[i-1])
                ++count;
            else {
                longest = max(longest, count);
                count = 1;
            }
        }
        return max(longest, count);
    }
};
