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
    int recurse(TreeNode *root, int &maxLength) {
        if(root == nullptr)
            return 0;
            
        int left = recurse(root->left, maxLength);
        int right = recurse(root->right, maxLength);
        
        maxLength = max(maxLength, left+right);
        
        return max(left, right) + 1;
    }
public:
    // Time: O(N), Space: O(N)
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int maxLength = 0;
        recurse(root, maxLength);
        return maxLength;
    }
};
