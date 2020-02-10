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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL) {
            if(root->val > val)
                root = root->left;
            else if (root->val < val)
                root = root->right;
            else
                return root;
        }
        
        return root;
    }
};
