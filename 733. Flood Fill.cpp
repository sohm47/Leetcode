class Solution {
    void dfs(vector<vector<int>>& image, int x, int y, int &currColor, int &newColor) {
        image[x][y] = newColor;
        if(x!=0 && image[x-1][y] == currColor) 
            dfs(image, x-1, y, currColor, newColor);
        if(y+1!=image[0].size() && image[x][y+1] == currColor) 
            dfs(image, x, y+1, currColor, newColor);
        if(x+1!=image.size() && image[x+1][y] == currColor) 
            dfs(image, x+1, y, currColor, newColor);
        if(y!=0 && image[x][y-1] == currColor) 
            dfs(image, x, y-1, currColor, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor = image[sr][sc];
        if(currColor != newColor)
            dfs(image, sr, sc, currColor, newColor);
            
        return image;
    }
};
