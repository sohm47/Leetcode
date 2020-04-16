class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int LEN = nums.size();
        
        vector<int> cache(2*LEN+1, -2);
        cache[LEN] = -1;
        
        int count = 0, maxLength = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1)
                count += 1;
            else
                count -= 1;
                
            if(cache[count+LEN] != -2)
                maxLength = max(maxLength, i-cache[count+LEN]);
            else
                cache[count+LEN] = i;
        }
        
        return maxLength;
    }
};
