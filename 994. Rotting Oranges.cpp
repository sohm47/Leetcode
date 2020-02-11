class Solution {
    int count(vector<vector<int>>& grid, vector<pair<int, int>> &rotten) {
        int countFresh = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2)
                    rotten.push_back({i, j});
                if(grid[i][j] == 1)
                    countFresh += 1;
            }
        }
        
        return countFresh;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> rotten;
        int countFresh = count(grid, rotten);
        if(countFresh == 0)
            return 0;
        if(rotten.size() == 0)
            return -1;
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        for(int i=0; i<rotten.size(); i++) {
            q.push({rotten[i].first, rotten[i].second});
            visited[rotten[i].first][rotten[i].second] = true;
        }
        
        int days = 0;
        while(!q.empty()) {
            days += 1;
            int size = q.size();
            for(int i=0; i<size; i++) {
                int r=q.front().first, c=q.front().second;
                q.pop();
                
                if(r!=0 && grid[r-1][c]==1 && !visited[r-1][c]) {
                    q.push({r-1, c});
                    visited[r-1][c] = true;
                    countFresh -= 1;
                }
                if(r+1!=grid.size() && grid[r+1][c]==1 && !visited[r+1][c]) {
                    q.push({r+1, c});
                    visited[r+1][c] = true;
                    countFresh -= 1;
                }
                if(c!=0 && grid[r][c-1]==1 && !visited[r][c-1]) {
                    q.push({r, c-1});
                    visited[r][c-1] = true;
                    countFresh -= 1;
                }
                if(c+1!=grid[0].size() && grid[r][c+1]==1 && !visited[r][c+1]) {
                    q.push({r, c+1});
                    visited[r][c+1] = true;
                    countFresh -= 1;
                }
                if(countFresh == 0)
                    return days;
            }
        }
        
        return -1;
    }
};
