class Solution {
public:
    // Time: O(N), Space: O(1)
    bool isIsomorphic(string s, string t) {
        vector<char> sToT(128, '\0'), tToS(128, '\0');
        for(int i=0; i<s.length(); i++) {
            if(sToT[s[i]] == '\0') {
                if(tToS[t[i]] != '\0')
                    return false;
                sToT[s[i]] = t[i];
                tToS[t[i]] = s[i];
            }
            else if(sToT[s[i]] != t[i])
                return false;
        }

        return true;
    }
};
