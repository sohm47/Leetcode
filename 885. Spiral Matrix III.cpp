class Solution {
public:
    // Time: O(max(R,C)), Space: O(1)
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R*C);
        ans[0] = {r0, c0};
        int rows[4] = {0, 1, 0, -1};
        int cols[4] = {1, 0, -1, 0};
        int total=1, steps=0;
        
        while(total < R*C) {
            for(int i=0; i<4; i++) {
                if(i%2 == 0)
                    ++steps;
                for(int j=0; j<steps; j++) {
                    r0 += rows[i];
                    c0 += cols[i];
                    if(r0>-1 && r0<R && c0>-1 && c0<C) {
                        ans[total] = {r0, c0};
                        ++total;
                    }
                }
            }
        }
        
        return ans;
    }
};
