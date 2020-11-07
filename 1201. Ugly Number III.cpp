class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long la = a, lb = b, lc = c, ln = n;
        long lcmab = lcm(la, lb), lcmac = lcm(la, lc), lcmbc = lcm(lb, lc);
        long lcmabc = lcm(lcmab, lc);
        
        long left = 1, right = 1000000000000000000;
        while(left<right) {
            long mid = left + (right-left)/2;
            long uglyNums = mid/la + mid/lb + mid/lc - mid/lcmab - mid/lcmbc - mid/lcmac + mid/lcmabc;
            
            if(n > uglyNums) 
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};
