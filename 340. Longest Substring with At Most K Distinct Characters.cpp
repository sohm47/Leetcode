class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.length() == 0 || k==0)
            return 0;
        if(s.length() == 1)
            return 1;
        
        int arr[256] = {0}, totalChars = 1, start=0, maxLen = 0;
        arr[s[0]] += 1;
        
        for(int i=1; i<s.length(); i++) {
            if(arr[s[i]] == 0) {
                if(totalChars<k) {
                    totalChars += 1;
                }
                else {
                    maxLen = max(maxLen, i-start);
                    for(int j=start; j<i; j++) {
                        arr[s[j]] -= 1;
                        if(arr[s[j]] == 0) {
                            start = j + 1;
                            break;
                        }
                    }             
                }
            }
            arr[s[i]] +=1;
        }
        
        return max(maxLen, int(s.length())-start);
    }
};
