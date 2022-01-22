class Solution {
    // Time: O(N), Space: O(1)
    public int maxArea(int[] height) {
        int left=0, right=height.length-1, area=0;
        
        while(left < right) {
            area = Math.max(area, ((int)Math.min(height[left], height[right])) * (right-left) );
            
            if(height[left] > height[right])
                right -= 1;
            else
                left += 1;
        }
        
        return area;
    }
}
