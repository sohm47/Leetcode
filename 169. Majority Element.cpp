class Solution {
public:
    // Time: O(N), Space: O(1)
    int majorityElement(vector<int>& nums) {
        int count = 0, majElem;
        for(int &num: nums) {
            if(count == 0)
                majElem = num;
            count += (num == majElem ? 1 : -1);
        }
        return majElem;
    }

    // Time: O(NlogN)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
	return nums[nums.size()/2];
    }
};
