class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> redAdj(n), blueAdj(n);
        for(vector<int> &neighbor: red_edges)
            redAdj[neighbor[0]].push_back(neighbor[1]);
        for(vector<int> &neighbor: blue_edges)
            blueAdj[neighbor[0]].push_back(neighbor[1]);
        
        // currNode, colorTo(0:red, 1:blue), pathLength
        queue<vector<int>> q;
        
        vector<int> redVisited(n, false);
        vector<int> blueVisited(n, false);
        
        for(int &neighbor: redAdj[0]) {
            q.push({neighbor, 0, 1});
            redVisited[neighbor] = true;
        }
        for(int &neighbor: blueAdj[0]) {
            q.push({neighbor, 1, 1});
            blueVisited[neighbor] = true;
        }
        
        vector<int> answer(n, INT_MAX);
        while(!q.empty()) {
            vector<int> front = q.front();
            q.pop();
            answer[front[0]] = min(answer[front[0]], front[2]);
            
            if(front[1] == 0) {
                for(int &neighbor: blueAdj[front[0]]) {
                    if(!blueVisited[neighbor]) {
                        blueVisited[neighbor] = true;
                        q.push({neighbor, 1, front[2]+1});
                    }
                }    
            }   
            else {
                for(int &neighbor: redAdj[front[0]]) {
                    if(!redVisited[neighbor]) {
                        redVisited[neighbor] = true;
                        q.push({neighbor, 0, front[2]+1});
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(!blueVisited[i] && !redVisited[i])
                answer[i] = -1;
        }
        answer[0] = 0;
            
        return answer;
    }
};
