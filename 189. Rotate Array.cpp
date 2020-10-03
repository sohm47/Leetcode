class Solution {
public:
    void reverse(vector<int> &nums, int start, int end) {
        while(start<end) {
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }

    // Time:O(N), Space: O(1)
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(k == 0)
            return;
        
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};
