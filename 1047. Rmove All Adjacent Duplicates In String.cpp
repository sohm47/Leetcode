class Solution {
public:
    string removeDuplicates(string S) {
        if(S.length() == 1)
            return S;
        
        stack<char> store;
        store.push(S[0]);
        for(int i=1; i<S.length(); i++) {
            if(!store.empty() && S[i] == store.top())
                store.pop();
            else
                store.push(S[i]);
        }
        
        string ans = "";
        while(!store.empty()) {
            ans.push_back(store.top());
            store.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
