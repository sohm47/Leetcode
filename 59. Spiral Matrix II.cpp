class Solution {
public:
    // Time: O(n*n), Space: O(n*n)
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int left=0, right=n, top=0, bottom=n, num=1;
        
        n = n*n;
        while(num<=n) {
            // left to right
            for(int i=left; i<right; i++)
                ans[top][i] = num++;
            
            // top to bottom
            --right;
            for(int i=top+1; i<bottom; i++)
                ans[i][right] = num++;
            
            // right to left
            --bottom;
            if(top<bottom)
                for(int i=right-1; i>left; i--)
                    ans[bottom][i] = num++;
            
            // bottom to top
            if(left<right)
                for(int i=bottom; i>top; i--)
                    ans[i][left] = num++;
            
            ++top, ++left;
        }
        return ans;
    }
};
