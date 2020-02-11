class Solution {
public:
    int minAddToMakeValid(string S) {
        int l = 0, r = 0;
        for(int i=0; i<S.length(); i++) {
            if(S[i] == '(')
                l += 1;
            else {
                if(l > 0) 
                    l -= 1;
                else
                    r += 1;
            }
        }
        
        return l+r;
    }
};
