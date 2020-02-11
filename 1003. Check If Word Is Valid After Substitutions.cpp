class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        
        for(char &c: S) {
            if(c == 'c') {
                if(s.empty() || s.top() != 'b')
                    return false;
                s.pop();
                if(s.empty() || s.top() != 'a')
                    return false;
                s.pop();
            }
            else 
                s.push(c);
        }
        
        return s.empty();
    }
};
