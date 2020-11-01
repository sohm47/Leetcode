class Solution {
    int find(vector<int> &parents, int a) {
        if(parents[a] == a)
            return a;
        parents[a] = find(parents, parents[a]);
        return parents[a];
    }
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<int> parents(n+1), children(n+1, 1);
        for(int i=1; i<=n; i++)
            parents[i] = i;
        
        for(int i=threshold+1; i<=n; i++) {
            for(int j=1; j*i<=n; j++) {
                int par1 = find(parents, i), par2 = find(parents, i*j);
                if(par1 != par2) {
                    if(children[par2] > children[par1]) {
                        parents[par1] = par2;
                        children[par2] += children[par1];
                    }
                    else {
                        parents[par2] = par1;
                        children[par1] += children[par2];
                    }
                }
            }
        }
        
        vector<bool> answer(queries.size(), false);
        int index = 0;
        for(vector<int> &query: queries) {
            if(parents[query[0]] == parents[query[1]] && parents[query[0]] != -1)
                answer[index] = true;
            ++index;
        }
        return answer;
    }
};
