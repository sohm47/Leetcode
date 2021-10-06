class Solution {
    int ROWS, COLS;
    int[] xDir = {-1, 0, 1, 0}, yDir = {0, 1, 0, -1};
    
    boolean checkBoundary(char[][] board, int x, int y) {
        return !(x<0 || y<0 || x == ROWS || y == COLS || board[x][y] != 'O');
    }
    
    void dfs(char[][] board, int x, int y) {
        board[x][y] = '#';
        
        for(int i=0; i<4; i++) {
            if(checkBoundary(board, x+xDir[i], y+yDir[i])) {
                dfs(board, x+xDir[i], y+yDir[i]);
            }
        }
    }
    // M = Rows, N = Columns
    // Time: O(M*N)
    // Space: O(M*N)
    public void solve(char[][] board) {
        ROWS = board.length;
        COLS = board[0].length;
        
        for(int x=0; x<ROWS; x++) {
            if(board[x][0] == 'O')
                dfs(board, x, 0);
            if(board[x][COLS-1] == 'O')
                dfs(board, x, COLS-1);
        }
        
        for(int y=0; y<COLS; y++) {
            if(board[0][y] == 'O')
                dfs(board, 0, y);
            if(board[ROWS-1][y] == 'O')
                dfs(board, ROWS-1, y);
        }
        
        for(int x=0; x<ROWS; x++) {
            for(int y=0; y<COLS; y++) {
                if(board[x][y] == 'O')
                    board[x][y] = 'X';
                if(board[x][y] == '#')
                    board[x][y] = 'O';
            }
        }
    }
}
