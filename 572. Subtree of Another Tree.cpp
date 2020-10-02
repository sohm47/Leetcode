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
    void preorder(TreeNode* node, string &str) {
        if(node == nullptr) {
            str.append(",#");
            return;
        }

        str.append("," + to_string(node->val));
        preorder(node->left, str);
        preorder(node->right, str);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        string strS = "", strT = "";
        preorder(s, strS);
        preorder(t, strT);
        
        return strS.find(strT) != -1;
    }
};
