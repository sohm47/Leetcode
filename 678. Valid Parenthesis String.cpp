class Solution {
public:
    // Time: O(N), Space: O(N)
    bool checkValidString(string s) {
        stack<int> asteriskIndex;
        stack<pair<char, int>> parens;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(')
                parens.push({s[i], i});
            else if(s[i]==')') {
                if(!parens.empty() && parens.top().first == '(')
                    parens.pop();
                else
                    parens.push({s[i], i});
            }
            else
                asteriskIndex.push(i);
        }
        
        while(!asteriskIndex.empty() || !parens.empty()) {
            if(!parens.empty()) {
                if(asteriskIndex.empty())
                    return false;
                if((parens.top().first == '(' && asteriskIndex.top()>parens.top().second) || (parens.top().first == ')' && asteriskIndex.top()<parens.top().second)) {
                    parens.pop();
                    asteriskIndex.pop();
                }
                else{
                    if(asteriskIndex.size()==1)
                        return false;
                    else {
                        asteriskIndex.pop();
                        asteriskIndex.pop();
                    }
                }
            }
            else
                return true;
        }
        
        return true;
    }
};
