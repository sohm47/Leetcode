class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        int schars[26] = {0}, tchars[26]={0};
        for(int i=0; i<s.length(); i++) {
            schars[s[i]-'a'] += 1;
            tchars[t[i]-'a'] += 1;
        }
    
        for(int i=0; i<26;i++)
            if(schars[i]!=tchars[i])
                return false;
            
        return true;
    }
    
};
