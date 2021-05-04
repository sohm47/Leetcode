// N = Size of words vector, K = max length of each string, Q = size of query vector 
// Time: O(N*K^2 + Q*K)
// Space: O(N*K^2)   

class WordFilter {
    struct Node {
        int index;
        vector<Node*> children;
        Node() {
            children.resize(27, nullptr);
        }
    };
    Node *root;
    
public:
    WordFilter(vector<string>& words) {
        root = new Node();
        
        for(int i=0; i<words.size(); i++) {
            string word = words[i] + "{" + words[i];
            for(int j=0; j<words[i].length(); j++) {
                Node *curr = root;
                for(int k=j; k<word.length(); k++) {
                    if(curr->children[word[k]-'a'] == nullptr) {
                        Node *temp = new Node();
                        curr->children[word[k]-'a'] = temp;
                    }
                    
                    curr = curr->children[word[k]-'a'];
                    curr->index = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        Node *curr = root;
        for(char &c: (suffix+"{"+prefix)) {
            if(curr->children[c-'a'] == nullptr)
                return -1;
            curr = curr->children[c-'a'];
        }
        return curr->index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
