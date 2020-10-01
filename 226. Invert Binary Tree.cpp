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
    // Time: O(N), Space: O(N)
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            
            TreeNode *temp = node->right;
            node->right = node->left;
            node->left = temp;
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        
        return root;
    }
};
