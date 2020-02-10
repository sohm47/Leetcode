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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return {0};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<double> answer;
        
        while(!q.empty()) {
            int size = q.size();
            double total = 0;
            for(int i=0; i<size; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                total += node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            answer.push_back(total/size);
        }
        
        return answer;
    }
};
