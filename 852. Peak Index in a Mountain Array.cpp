class Solution {
public:
    // Time: O(NlogN), Space: O(1)
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0, mid, hi = A.size();
        while(lo<hi) {
            mid = lo + (hi-lo)/2;
            if(A[mid]<A[mid+1]) 
                lo = mid+1;
            else
                hi = mid;
        }
        return lo;
    }
};
