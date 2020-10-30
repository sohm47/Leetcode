class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, mid, right = *max_element(piles.begin(), piles.end());
        while(left<right) {
            mid = left+(right-left)/2;
            
            int total = 0;
            for(int i=0; i<piles.size() && total<=H; i++)
                total += ceil(piles[i]/float(mid));
            
            if(total <= H)
                right = mid;
            else
                left = mid+1;
        }
        
        return left;
    }
};
