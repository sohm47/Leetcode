/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        if(dimensions[0]*dimensions[1] == 0)
            return -1;
        
        int ROWS = dimensions[0], j=dimensions[1]-1; 
        for(int i=0; i<ROWS; i++) {
            while(j != -1 && binaryMatrix.get(i, j) == 1)
                --j;
            if(j == -1)
                return 0;
        }
        
        return j == dimensions[1]-1 ? -1 : j+1;
    }
};
