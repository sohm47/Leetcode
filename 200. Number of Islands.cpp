class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
        visited[i][j] = true;
        if(i!=0 && grid[i-1][j] == '1' && !visited[i-1][j])
            dfs(grid, visited, i-1, j);
        if(i+1!=grid.size() && grid[i+1][j] == '1' && !visited[i+1][j])
            dfs(grid, visited, i+1, j);
        if(j!=0 && grid[i][j-1] == '1' && !visited[i][j-1])
            dfs(grid, visited, i, j-1);
        if(j+1!=grid[0].size() && grid[i][j+1] == '1' && !visited[i][j+1])
            dfs(grid, visited, i, j+1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0)
            return 0;
            
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    count += 1;
                }       
            }
        }
        
        return count;
    }
};
