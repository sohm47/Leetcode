class Solution {
    int good(string word, vector<int> charsCount) {
        for(char &c: word) {
            if(charsCount[c-'a']-- == 0)
                return 0;
        }
        return word.length();
    }
    
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charsCount(26, 0);
        for(char &c: chars)
            charsCount[c-'a'] += 1;
        
        int count=0;
        for(string &word: words) {
            count += good(word, charsCount);
        }
        
        return count;
    }
};
