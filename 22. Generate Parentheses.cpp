class Solution {
    int maxLen;
    void solve(vector<string> &ret, int left, int right, string s) {
        if(s.length() == maxLen) {
            ret.push_back(s);
            return;
        }
        
        if(left>0)
            solve(ret, left-1, right, s+"(");
        if(left<right)
            solve(ret, left, right-1, s+")");
    }
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {""};
            
        maxLen = n*2;
        vector<string> ret;
        solve(ret, n, n, "");
        
        return ret;
    }
};
