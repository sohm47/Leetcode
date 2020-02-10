/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root || (!root->left && !root->right))
            return false;

        stack<TreeNode *> s;
        s.push(root);
        set<int> cache;
        
        while(!s.empty()) {
            TreeNode *top = s.top();
            s.pop();
            if(cache.find(top->val) != cache.end())
                return true;
            
            cache.insert(k-top->val);
            if(top->left)
                s.push(top->left);
            if(top->right)
                s.push(top->right);
        }
        
        return false;
    }
};
