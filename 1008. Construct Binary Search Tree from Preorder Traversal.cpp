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
    int i;
    TreeNode* recurse(vector<int>& preorder, int maxValue) {
        if(i >= preorder.size() || preorder[i] > maxValue)
            return nullptr;
        
        TreeNode *node = new TreeNode(preorder[i++]);
        node->left = recurse(preorder, node->val);
        node->right = recurse(preorder, maxValue);
        
        return node;
    }
    
    // Time: O(N), Space: O(N)
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        i = 0;
        return recurse(preorder, INT_MAX);
    }
};
