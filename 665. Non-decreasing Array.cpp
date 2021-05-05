class Solution {
public:
    // Time: O(N), Space: O(1)
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        
        for(int i=1; i<nums.size() && count < 2; i++) {
            if(nums[i-1] > nums[i]) {
                ++count;
                if(i-2 > -1 && nums[i-2]>nums[i])
                    nums[i] = nums[i-1];
            }
        }
        
        return count < 2;
    }
};
