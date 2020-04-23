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
    int recurse(TreeNode* root, int child) {
        if(root == nullptr)
            return 0;
        
        if(!root->left && !root->right && child == 1)
            return root->val;
        
        int left = recurse(root->left, 1);
        int right = recurse(root->right, 2);
        return left+right;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return recurse(root, 0);
    }
};
