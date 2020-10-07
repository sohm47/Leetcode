class Solution {
public:
    // Time: O(N), Space: O(1)
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<nums[i-1]) {
                if(i>1 && nums[i]<nums[i-2] && i+1 != nums.size() && nums[i+1]<nums[i-1])
                    return false;
                else if(++count > 1)
                    return false;
            }
        }
        return true;
    }
};
