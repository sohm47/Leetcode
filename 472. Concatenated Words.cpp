class Solution {
    struct Trie {
        bool isEnd;
        vector<Trie*> children;
        Trie() {
            isEnd = false;
            children.resize(26, nullptr);
        }
    };
    
    void addWord(string &word, Trie *root) {
        Trie *temp = root;
        for(char &c: word) {
            if(temp->children[c-'a'] == nullptr)
                temp->children[c-'a'] = new Trie();
            temp = temp->children[c-'a'];
        }
        
        temp->isEnd = true;
    }
    
    bool checkWords(string &word, int &len, Trie *root, int index, int count) {
        Trie *temp = root;
        for(int i=index; i<len; ++i) {
            if(temp->children[word[i]-'a'] == nullptr)
                return false;
            if(temp->children[word[i]-'a']->isEnd) {
                if(i == len-1)
                    return count>0;
                if(checkWords(word, len, root, i+1, count+1))
                    return true;
            }
            temp = temp->children[word[i]-'a'];
        }
        
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> concatenatedWords;
        if(words.size() == 0)
            return concatenatedWords;
        
        Trie *root = new Trie();
        for(string &word: words)
            addWord(word, root);
        
        for(string &word: words) {
            int len = word.length();
            if(checkWords(word, len, root, 0, 0))
                concatenatedWords.push_back(word);
        }
        
        return concatenatedWords;
    }
};
