class Solution {
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &ans, vector<int> path, int node) {
        if(node == graph.size()-1) {
            ans.push_back(path);
            return;
        }
        
        for(int i=0; i<graph[node].size(); i++) {
            path.push_back(graph[node][i]);
            dfs(graph, ans, path, graph[node][i]);
            path.pop_back();  
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        for(int i=0; i<graph[0].size(); i++) {
            path.push_back(graph[0][i]);
            dfs(graph, ans, path, graph[0][i]);
            path.pop_back();
        }
        
        return ans;
    }
};
