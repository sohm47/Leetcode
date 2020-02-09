class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 1)
            return res;
        
        for(int i=0; i<nums.size(); i++) {
            int index = abs(nums[i])-1;
            if(nums[index] > 0)
                nums[index] = -nums[index];
        }
        
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] > 0) 
                res.push_back(i+1);
        }
        
        return res;
    }
};
