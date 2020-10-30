class Solution {
public:
    bool capacity(vector<int>& weights, int &D, int &sum) {
        int total = 0, days = 0;
        for(int &weight: weights) {
            total += weight;
            if(total > sum) {
                total = weight;
                ++days;
                if(days > D)
                    return false;
            }
        }
        
        return days < D;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int mid;
        int right = accumulate(weights.begin(), weights.end(), 0);
        while(left<right) {
            mid = left+(right-left)/2;
            if(capacity(weights, D, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
