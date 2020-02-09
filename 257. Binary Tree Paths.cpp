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
    void solve(vector<string> &ret, TreeNode* root, string s) {
        if(!root->left && !root->right) {
            ret.push_back(s);
            return;
        }
        if(root->left) 
            solve(ret, root->left, s + "->" + to_string(root->left->val));
        if(root->right) 
            solve(ret, root->right, s + "->" + to_string(root->right->val));
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return {};
            
        vector<string> ret;
        solve(ret, root, to_string(root->val));
        
        return ret;
    }
};
