class Solution {
public:
    // Time: O(N), Space: O(1)
    bool canJump(vector<int>& nums) {
        int jump = 0;
        for(int i=0; i<nums.size(); i++) {
            if(jump == 0 && nums[i] == 0 && i != nums.size()-1)
                return false;
            if(nums[i] > jump)
                jump += nums[i]-jump;
            --jump;
        }
        
        return true;
    }
};
