class Solution {
public:
    int characterReplacement(string s, int k) {
        int right=0, uniq=0, maxCount=0, longest = 0;
        vector<int> counts(26, 0);
        for(int left=0; left<s.length(); left++) {
            while(right < s.length() && uniq<=k+1) {
                if(++counts[s[right]-'A'] == 1)
                    ++uniq;
                maxCount = max(maxCount, counts[s[right]-'A']);
                ++right;
                if(right-left-maxCount > k) {
                    longest = max(longest, right-left-1);
                    break;
                }
                longest = max(longest, right-left);
            }
            if(--counts[s[left]-'A'] == 0)
                --uniq;
        }
        
        return longest;
    }
};
