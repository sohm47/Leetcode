class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> unique;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(string word: words) {
            string ans = "";
            for(char l: word) {
                ans += morse[l-'a']   ;         
            }
            unique.insert(ans);
        }
        
        return unique.size();
    }
};
