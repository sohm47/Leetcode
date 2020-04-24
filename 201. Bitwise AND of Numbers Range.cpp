class Solution {
public:
    // Time: O(1), Space: O(1)
    int rangeBitwiseAnd(int m, int n) {
        long diff = n-m, num = 1;
        while(num<diff)
            num *= 2;
        
        return n&(~int(num-1)&m);
    }
};
