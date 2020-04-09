class Solution {
public:
    // Solution 1
    // Time: O(N), Space: O(1) 
    bool backspaceCompare(string S, string T) {
        int i=S.length()-1, j=T.length()-1;
        
        while(i>=0 || j>=0) {
            if(i>=0 && S[i] == '#') {
                int count = 1;
                i -= 1;
                do {
                    while(i>=0 && S[i]=='#') {
                        ++count;
                        --i;
                    }
                    while(i>=0 && S[i]!='#' && count>0) {
                        --count;
                        --i;
                    }
                } while(count!=0 && i>=0);
            }
            
            if(j>=0 && T[j] == '#') {
                int count = 1;
                j -= 1;
                do {
                    while(j>=0 && T[j]=='#') {
                        ++count;
                        --j;
                    }
                    while(j>=0 && T[j]!='#' && count>0) {
                        --count;
                        --j;
                    }
                } while(count!=0 && j>=0);
            }
            
            if(i<0 && j<0)
                return true;
            if(i<0 && T[j] == '#') 
                continue;
            if(j<0 && S[i] == '#')
                continue;
            if(i<0 || j<0)
                return false;
            if(S[i]=='#' || T[j]=='#')
                continue;
            if(S[i]!=T[j])
                return false;
                
            --i;
            --j;
        }
        
        if(i>=0 || j>=0)
            return false;
            
        return true;
    }
    
    // Solution 2
    // Time: O(N), Space: O(N)
    bool backspaceCompare2(string S, string T) {
        stack<char> first, second;
        for(char &c: S) {
            if(c == '#') {
                if(!first.empty())
                    first.pop();
            }
            else
                first.push(c);
        }
        for(char &c: T) {
            if(c == '#') {
                if(!second.empty())
                    second.pop();
            }
            else
                second.push(c);
        }
        
        if(first.size() != second.size())
            return false;
        
        while(!first.empty()) {
            if(first.top() != second.top())
                return false;
            first.pop();
            second.pop();
        }
        
        return true;
    }
};
