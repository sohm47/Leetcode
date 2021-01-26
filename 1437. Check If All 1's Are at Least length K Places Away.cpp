class Solution {
public:
    // Time: O(N), Space: O(1)
    bool kLengthApart(vector<int>& nums, int k) {
        int dist = k;
        for(int &num: nums) {
            ++dist;
            if(num == 1) {
                if(dist < k)
                    return false;
                dist = -1;
            }
        }
        return true;
    }
};
