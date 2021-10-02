class Solution {
    // Time: O(N)
    // Space: O(N)
    public int largestRectangleArea(int[] heights) {
        int maxArea = 0;
        int[] left = new int[heights.length];
        left[0] = -1;
        for(int i=1; i<heights.length; i++) {
            int index = i-1;
            while(index != -1 && heights[index] >= heights[i]) {
                index = left[index];
            }
            left[i] = index;
        }
        
        int[] right = new int[heights.length];
        right[right.length-1] = right.length;
        for(int i=right.length-2; i >= 0; i--) {
            int index = i+1;
            while(index != right.length && heights[index] >= heights[i]) {
                index = right[index];
            }
            right[i] = index;
        }
        
        for(int i=0; i<heights.length; i++) {
            maxArea = Math.max(maxArea, heights[i]*(right[i]-left[i]-1));
        }
        
        return maxArea;
    }
}
