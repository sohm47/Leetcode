class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool stable = false;
        while(!stable) {
            stable = true;
            
            // negative number for all candies that need to be crushed
            for(int i=0; i<board.size(); i++) {
                for(int j=0; j<board[i].size(); j++) {
                    if(board[i][j]!=0) {
                        // check right
                        int k=0;
                        while(j+k != board[i].size() && abs(board[i][j])==abs(board[i][j+k])) {
                            k += 1;
                        }
                        if(k>2) {
                            stable = false;
                            int index = 0;
                            while(index != k) {
                                if(board[i][j+index]>0)
                                    board[i][j+index] = -board[i][j+index];
                                index += 1;
                            }
                        }

                        // check bottom
                        k=0;
                        while(i+k != board.size() && abs(board[i][j]) == abs(board[i+k][j])) {
                            k+=1;
                        }
                        if(k>2) {
                            stable = false;
                            int index = 0;
                            while(index != k) {
                                if(board[i+index][j]>0)
                                    board[i+index][j] = -board[i+index][j];
                                index += 1;
                            }
                        }
                    }
                }
            }
            
            // crush
            if(!stable) {
                for(int j=0; j<board[0].size(); j++) {
                    int bottom=board.size()-1, top=board.size()-1;
                    while(bottom>=0 && top>=0) {
                        if(board[top][j]>=0) {
                            swap(board[bottom][j], board[top][j]);
                            bottom -=1;
                        }
                        top -= 1;                
                    }
                    while(bottom>=0) {
                        board[bottom][j] = 0;
                        bottom -=1;
                    }
                }
            }
        }
        
        return board;
    }
};
