class Solution {
public:
    // Time: O(log(n)), Space: O(1)
    int rangeBitwiseAnd(int m, int n) {
        long diff = n-m, num = 1;
        while(num<diff)
            num <<= 1;
        
        return (m&n)&~int(num-1);
    }
};
