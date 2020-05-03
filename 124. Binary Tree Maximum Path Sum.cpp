/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum;
    
    // Time: O(N), Space: O(N)
    int recurse(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int left = max(recurse(root->left), 0);
        int right = max(recurse(root->right), 0);
        
        maxSum = max(maxSum, left+right+root->val);
        if(left < 0 && right < 0)
            return root->val;
        return (left>right? left : right) + root->val;
    }
    
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        recurse(root);
        return maxSum;
    }
};
