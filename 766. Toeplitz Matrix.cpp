class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unsigned int rows = matrix.size(), cols = matrix[0].size();
        
        for(unsigned int i=1;i<rows; i++) {
            for(unsigned int j=1; j<cols; j++) {
                if(matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
