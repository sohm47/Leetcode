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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        int longest = 1, val;
        TreeNode *node;
        
        while(!q.empty()) {
            node = q.front().first;
            val = q.front().second;
            q.pop();
            
            if(node->left) {
                if(node->left->val-node->val == 1)
                    q.push({node->left, val+1});
                else{
                    longest = max(longest, val);
                    q.push({node->left, 1});
                }
            }
            
            if(node->right) {
                if(node->right->val-node->val == 1)
                    q.push({node->right, val+1});
                else{
                    longest = max(longest, val);
                    q.push({node->right, 1});
                }
            }
            
            longest = max(longest, val);
        }
        
        return max(longest, val);
    }
};
