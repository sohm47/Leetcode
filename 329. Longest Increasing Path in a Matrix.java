class Solution {
    int ROWS, COLS;
    int[][] dp;
    
    int[] xDir = {-1, 0, 1, 0}, yDir = {0, 1, 0, -1};
    
    int dfs(int[][] matrix, int row, int col, int previousValue) {
        if(row < 0 || row == ROWS || col < 0 || col == COLS || matrix[row][col] <= previousValue)
            return 0;
        
        if(dp[row][col] != 0)
            return dp[row][col];
        
        int longestPath = 0;
        for(int i=0; i<4; i++) {
            longestPath = Math.max(longestPath, dfs(matrix, row+xDir[i], col+yDir[i], matrix[row][col]));
        }
        
        dp[row][col] = longestPath+1;
        return longestPath+1;
    }
 
    // M = rows
    // N = cols
    // Time: O(M*N)
    // Space: O(M*N)   
    public int longestIncreasingPath(int[][] matrix) {
        ROWS = matrix.length;
        COLS = matrix[0].length;
        dp = new int[ROWS][COLS];
        
        int longestPath = 1;
        for(int row=0; row<ROWS; row++) {
            for(int col=0; col<COLS; col++) {
                longestPath = Math.max(longestPath, dfs(matrix, row, col, -1));
            }
        }
        
        return longestPath;
    }
}
