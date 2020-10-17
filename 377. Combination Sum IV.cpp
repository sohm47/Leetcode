class Solution {
public:
    // Bottom-up
    // Time: O(N*target), Space:O(target)
    int combinationSum4(vector<int>& nums, int target) {
        int LEN = target+1;
        vector<unsigned int> dp(LEN);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i=1; i<LEN; i++) {
            for(int j=0; j<nums.size() && i-nums[j]>=0; j++) {
                dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }

    // Top-down
    
    int recurse(vector<int>& nums, unordered_map<int, int>& cache, int sum) {
        if(sum == 0)
            return 1;

        cache[sum] = 0;
        for(int i=0; i<nums.size() && sum-nums[i]>=0; i++) {
            if(cache.find(sum-nums[i]) == cache.end())
                cache[sum] += recurse(nums, cache, sum-nums[i]);
            else
                cache[sum] += cache[sum-nums[i]];
        }
        return cache[sum];
    }

    //Time: O(N*target), Space: O(target)
    int combinationSum4_2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cache = {{0, 1}};
        return recurse(nums, cache, target);
    }
};
