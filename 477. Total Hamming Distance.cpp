class Solution {
public:
    // Time: O(N), Space: O(1)
    int totalHammingDistance(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<32; i++) {
            int ones = 0;
            for(int &num: nums){
                if(num&1 == 1)
                    ++ones;
                num >>= 1;
            }
            count += (ones*(nums.size()-ones));
        }
        
        return count;
    }
};
