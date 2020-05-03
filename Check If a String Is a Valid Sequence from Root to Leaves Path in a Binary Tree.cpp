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
    bool dfs(TreeNode* root, vector<int>& arr, int index) {
        if(root == nullptr || arr.size() == index || root->val != arr[index])
            return false;

        return (!root->left && !root->right && index == arr.size()-1) || dfs(root->left, arr, index+1) || dfs(root->right, arr, index+1);
    }
public:

    // N = total nodes in Binary Tree
    // Time: O(N), Space: O(N) 
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
};
