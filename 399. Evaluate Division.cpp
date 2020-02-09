class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    
    pair<bool, double> dfs(string& a, string& b, unordered_set<string>& visited, double val) {
        if (visited.count(a) == 0) {
            visited.insert(a);
            for (pair<string, double> p : adj[a]) {
                double temp = val * p.second;
                if (p.first == b) 
                    return make_pair(true, temp);
                
                auto result = dfs(p.first, b, visited, temp);
                if (result.first) 
                    return result;
            }
        }
        
        return make_pair(false, -1.0);
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0; i<equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        
        vector<double> ret;
        for(vector<string> &query: queries) {
            if(adj.find(query[0]) == adj.end() || adj.find(query[1]) == adj.end())
                ret.push_back(-1);
            else if(query[0] == query[1])
                ret.push_back(1);
            else { //dfs
                unordered_set<string> visited;
                ret.push_back(dfs(query[0], query[1], visited, 1.0).second);
            }
        }
        
        return ret;
    }
};
