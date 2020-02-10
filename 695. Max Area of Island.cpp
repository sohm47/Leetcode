class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int &currArea, int i, int j) {
        visited[i][j] = true;
        currArea += 1;
        if(i-1!=-1 && grid[i-1][j] == 1 && !visited[i-1][j])
            dfs(grid, visited, currArea, i-1, j);
        if(j-1!=-1 && grid[i][j-1] == 1 && !visited[i][j-1])
            dfs(grid, visited, currArea, i, j-1);
        if(i+1!=grid.size() && grid[i+1][j] == 1 && !visited[i+1][j])
            dfs(grid, visited, currArea, i+1, j);
        if(j+1!=grid[0].size() && grid[i][j+1] == 1 && !visited[i][j+1])
            dfs(grid, visited, currArea, i, j+1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int currArea = 0;
                    dfs(grid, visited, currArea, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;
    }
};
