class Solution {
public:
    int countSubstrings(string s) {
        if(s.length() < 2)
            return s.length();
        
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            // check odd
            int j=1, len = min(i, int(s.length())-i);
            while(j<(len+1)) {
                if(s[i-j] != s[i+j])
                    break;
                count += 1;
                j++;
            }
            
            // check even
            j=0, len = min(i, int(s.length())-i);
            while(j!=len+1) {
                if(s[i-j]!=s[i+j+1])
                    break;
                count += 1;
                j++;
            }
        }
        
        return count+s.length();
    }
};
