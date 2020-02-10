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
        set<int> m;
        s.push(root);
        
        while(!s.empty()) {
            TreeNode *top = s.top();
            s.pop();
            if(m.find(top->val) != m.end())
                return true;
            
            m.insert(k-top->val);
            if(top->left)
                s.push(top->left);
            if(top->right)
                s.push(top->right);
        }
        
        return false;
    }
};
