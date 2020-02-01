class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        for(int i=0; i<nums.size(); i++) {
            if(cache.find(nums[i]) != cache.end()) {
                return {i, cache[nums[i]]};    
            }
            cache[target-nums[i]] = i;
        }
        
        return {-1,-1};
    }
};
