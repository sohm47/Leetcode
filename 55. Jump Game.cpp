class Solution {
public:
    // Time: O(N), Space: O(1)
    bool canJump(vector<int>& nums) {
        int currEnd = 0, currFarthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            currFarthest = max(currFarthest, i + nums[i]);
            if (i == currEnd) {
                currEnd = currFarthest;
                if(i == currEnd)
                    return false;
            }
        }
        return true;
    }
};
