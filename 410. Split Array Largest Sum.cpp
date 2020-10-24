class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left<right) {
            int mid = left + (right-left)/2, total = 1, sum = 0;
            for(int &num: nums) {
                sum += num;
                if(sum > mid) {
                    sum = num;
                    ++total;
                    if(total > m)
                        break;
                }
            }
            if(total > m)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};
