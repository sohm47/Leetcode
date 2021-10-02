class Solution {
    // Code from problem '84. Largest Rectangle in Histogram'
    private int largestRectangleArea(int[] heights) {

    }
    

    // M = rows, N = columns
    // Time: O(M*N)
    // Space: O(N)
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length == 0)
            return 0;
        
        int[] heights = new int[matrix[0].length];
        for(int i=0; i<matrix[0].length; i++) {
            heights[i] = Character.getNumericValue(matrix[0][i]);
        }
        int maxArea = largestRectangleArea(heights);
        
        for(int i=1; i<matrix.length; i++) {
            for(int j=0; j<matrix[0].length; j++) {
                heights[j] = (matrix[i][j] == '0' ? 0 : heights[j]+1);
            }
            maxArea = Math.max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }
}
