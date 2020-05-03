class Solution {
public:
    // Time: O(M+N), Space: O(1)
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        for(char &c: magazine)
            ++arr[c-'a'];
        for(char &c: ransomNote)
            if(--arr[c-'a'] < 0)
                return false;
        return true;
    }
};
