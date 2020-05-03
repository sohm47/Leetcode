// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // Time: O(logN), Space: O(1)
    int firstBadVersion(int n) {
        int lo = 1, mid, hi = n;
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            if(isBadVersion(mid))
                hi = mid;
            else
                lo = mid+1;
        }
        
        return lo;
    }
};
