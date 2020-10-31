class Solution {
public:
    // Time: O((m*n)Log(m*n)), Space: O(1)
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m*n;
        while(left<right) {
            int mid = left + (right-left)/2;
            int count = 0, row = mid/n, col = mid/m;
            for(int i=1; i<=mid && i<=n; i++)
                count += min(mid/i, m);
            
            if(count < k) 
                left = mid + 1;
            else
                right = mid; 
        }
        
        return left;
    }
};
