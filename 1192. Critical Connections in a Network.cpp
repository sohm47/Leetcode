class Solution {
    void dfs(vector<vector<int>> &answer, vector<vector<int>> &adj, vector<bool> &visited, int &time, vector<int> &visitedTime, vector<int> &lowTime, vector<int> &parent, int curr) {
        ++time;
        visitedTime[curr] = time;
        lowTime[curr] = time;
        
        for(int &neighbor: adj[curr]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                dfs(answer, adj, visited, time, visitedTime, lowTime, parent, neighbor);
            }
            
            if(parent[curr] != neighbor)
                lowTime[curr] = min(lowTime[curr], lowTime[neighbor]);
        }
        
        if(lowTime[curr] > visitedTime[parent[curr]])
            answer.push_back({curr, parent[curr]});
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(vector<int> &connection: connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        vector<int> visitedTime(n), lowTime(n), parent(n);
        vector<vector<int>> answer;
        vector<bool> visited(n);
        int time = 0;
        
        visitedTime[0] = 0, lowTime[0] = 0, parent[0] = 0, visited[0] = true;
        for(int &neighbor: adj[0]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = 0;
                dfs(answer, adj, visited, time, visitedTime, lowTime, parent, neighbor);
            }
        }
        
        return answer;
    }
};
