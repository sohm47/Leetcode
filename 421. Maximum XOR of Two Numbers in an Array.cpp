class Solution {
    struct Trie {
        int value;
        Trie *child[2];
        Trie() {
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };
    
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        for(int &num: nums) {
            Trie *curr = root;
            for(int i=30; i>=0; i--) {
                int currBit = (num>>i)&1;
                if(curr->child[currBit] == nullptr)
                    curr->child[currBit] = new Trie();
                curr = curr->child[currBit];
            }
            curr->value = num;
        }
        
        int maxValue = INT_MIN;
        for(int &num: nums) {
            Trie *curr = root;
            for(int i=30; i>=0; i--) {
                int currBit = (num>>i)&1;
                if(curr->child[!currBit])
                    curr = curr->child[!currBit];
                else
                    curr = curr->child[currBit];
            }
            
            maxValue = max(maxValue, curr->value^num);
        }
        
        return maxValue;
    }
};
