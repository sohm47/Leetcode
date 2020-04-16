class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prods(nums.size());
        prods[0] = 1;
        
        for(int i=1; i<nums.size(); i++)
            prods[i] = nums[i-1] * prods[i-1];

        int rightProds = 1;
        for(int i=nums.size()-2; i!=-1; i--) {
            rightProds *= nums[i+1];
            prods[i] *= rightProds;
        }
        
        return prods;
    }
};
