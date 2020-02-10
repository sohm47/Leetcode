class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size() == 1)
            return{0};
        if(T.size() == 0)
            return {};
        
        vector<int> ret(T.size(), 0);
        stack<pair<int,int>> s;
        s.push(make_pair(T[0], 0));
        
        for(int i=1; i<T.size(); i++) {
            if(!s.empty() && s.top().first < T[i]) {
                while(!s.empty() && s.top().first<T[i]) {
                    ret[s.top().second] = i-s.top().second;
                    s.pop();
                }
            }
            s.push(make_pair(T[i], i));
        }
        
        return ret;
    }
};
