class Solution {
    struct Trie {
        bool isLast;
        vector<Trie*> children;
        Trie() {
            isLast = false;
            children.resize(26, nullptr);
        }
    };
    
    void addToTrie(Trie *root, string &prod) {
        Trie *curr = root;
        for(char &c: prod) {
            if(!curr->children[c-'a'])
                curr->children[c-'a'] = new Trie();
            curr = curr->children[c-'a'];
        }
        
        curr->isLast = true;
    }
    
    void dfs(Trie *root, string &search, vector<string> &temp, string &sugg) {
        if(temp.size()<3) {
            if(root->isLast)
                temp.push_back(sugg);
        }
        
        if(temp.size() == 3)
            return;
        
        for(int i=0; i<26; i++) {
            if(root->children[i]) {
                sugg.push_back(char('a'+i));
                dfs(root->children[i], search, temp, sugg);
                sugg.pop_back();
            }
            if(temp.size() == 3)
                return;
        }
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *root = new Trie();
        for(string &prod: products) {
            addToTrie(root, prod);
        }
        
        string search = "";
        vector<vector<string>> ret;
        for(char &c: searchWord) {
            search.push_back(c);
            Trie *curr = root;
            bool foundWord = true;
            for(char &c: search) {
                if(curr->children[c-'a'])
                    curr = curr->children[c-'a'];
                else {
                    foundWord = false;
                    break;
                }
            }
            
            vector<string> temp;
            if(foundWord)
                dfs(curr, search, temp, search);                
            
            ret.push_back(temp);
        }
        
        return ret;
    }
};
