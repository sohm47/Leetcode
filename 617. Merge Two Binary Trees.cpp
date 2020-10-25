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
    void preorder(TreeNode *t1, TreeNode *t2) {
        if(!t1 && !t2)
            return;
        t1->val = t1->val + t2->val;
        if(!t1->left && t2->left)
            t1->left = t2->left;
        else if(t2->left)
            preorder(t1->left, t2->left);
            
        if(!t1->right && t2->right)
            t1->right = t2->right;
        else if(t2->right)
            preorder(t1->right, t2->right);
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)
            t1 = t2;
        else if(t2)
            preorder(t1, t2);
        return t1;
    }
};
