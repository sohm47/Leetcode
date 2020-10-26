class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(k*m > bloomDay.size())
            return -1;
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(left<right) {
            int mid = left+(right-left)/2;
            
            int bouquets = 0;
            for(int i=0; i<bloomDay.size() && bouquets<=m; i++) {
                if(bloomDay[i] <= mid) { 
                    int j = i+1;
                    while(j<bloomDay.size() && j<i+k && bloomDay[j] <= mid )
                        ++j;
                    if(j == i+k)
                        ++bouquets;
                    
                    i = j-1;
                }
            }
            
            if(bouquets<m)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};
