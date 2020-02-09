class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cache;
        for(int i=0; i<s.length(); i++)
            ++cache[s[i]];
        
        for(int i=0; i<s.length(); i++)
            if(cache[s[i]] == 1)
                return i;
                
        return -1;
    }
};
