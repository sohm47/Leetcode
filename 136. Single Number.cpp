class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number=nums[0];
        for(int i=1; i<nums.size(); i++) {
            number ^= nums[i];
        }
        
        return number;
    }
};
