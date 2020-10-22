class Solution {
public:
    // Time: O(logN), Space: O(1)
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        if(x < 4)
            return 1;
        
        long int left = 0, mid, right = x/2 + 1;
        while(left<right) {
            mid = left+(right-left)/2;
            if(mid*mid>x)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left-1;
    }
};
