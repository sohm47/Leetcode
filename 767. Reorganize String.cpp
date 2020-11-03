class Solution {
public:
    string reorganizeString(string S) {
        vector<pair<char, int>> freq(26);
        for(int i=0; i<26; i++)
            freq[i] = {i+'a', 0};
        for(int i=0; i<S.length(); i++)
            ++freq[S[i]-'a'].second;
        
        auto compare = [&](pair<char, int> &a, pair<char, int> &b) {
            return a.second<b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> q(compare);
        for(pair<char, int> &f: freq) {
            if(f.second > (S.length()+1)/2)
                return "";
            if(f.second > 0)
                q.push(f);
        }
        
        string ans = "";
        while(q.size()>1) {
            pair<int, int> top1 = q.top();
            q.pop();
            pair<int, int> top2 = q.top();
            q.pop();
            
            ans.push_back(top1.first);
            ans.push_back(top2.first);
            
            if(--top1.second > 0)
                q.push(top1);
            if(--top2.second > 0)
                q.push(top2);
        }
        
        if(q.size() == 1)
            ans.push_back(q.top().first);
        return ans;
    }
};
