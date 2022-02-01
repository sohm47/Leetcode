class Solution {
public:
    bool isValid(string s) {
        stack<char> cache;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                cache.push(s[i]);
            }
            else if(s[i] == ')') {
                if(cache.size() == 0)
                    return false;
                
                if(cache.top() == '(')
                    cache.pop();
                else
                    return false;
            }
            else if(s[i] == ']') {
                if(cache.size() == 0)
                    return false;
                
                if(cache.top() == '[')
                    cache.pop();
                else
                    return false;
                
            }
            else if(s[i] == '}') {
                if(cache.size() == 0)
                    return false;
                
                if(cache.top() == '{')
                    cache.pop();
                else
                    return false;
            }
        }
        
        return cache.size() == 0;
    }
};
