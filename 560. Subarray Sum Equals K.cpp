class Solution {
public:
    // Time: O(N), Space:O(N)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> cache;
        cache[0] = 1;
        int LEN = nums.size(), sum=0, count=0;
        for(int i=0; i<LEN; i++) {
            sum += nums[i];
            
            if(cache.find(sum-k) != cache.end())
                count += cache[sum-k];
            
            if(cache.find(sum) == cache.end())
                cache[sum] = 1;
            else
                ++cache[sum];
        }
        
        return count;
    }
};
