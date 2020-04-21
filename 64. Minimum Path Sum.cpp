class Solution {
public:
    // Time: O(MxN), Space: O(1)
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int ROWS = grid.size(), COLS = grid[0].size();
        
        for(int i=1; i<ROWS; i++)
            grid[i][0] += grid[i-1][0];
        for(int i=1; i<COLS; i++)
            grid[0][i] += grid[0][i-1];
        
        for(int i=1; i<ROWS; i++) {
            for(int j=1; j<COLS; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[ROWS-1][COLS-1];  
    }
};
