/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    vector<string> split(string &data) {
        vector<string> values;
        values.push_back("");
        for(int i=0; i<data.length(); i++) {
            if(data[i] == ',')
                values.push_back("");
            else
                values.back().push_back(data[i]);
        }
        return values;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "n";
            
        queue<TreeNode*> q;
        q.push(root);
        string data = to_string(root->val);
        
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<q.size(); i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) {
                    q.push(temp->left);
                    data += "," + to_string(temp->left->val);
                }
                else
                    data += ",n";
                
                if(temp->right) {
                    q.push(temp->right);
                    data += "," + to_string(temp->right->val);
                }
                else
                    data += ",n";
            }
        }
        
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == 'n')
            return NULL;
        
        vector<string> values = split(data);
        
        TreeNode* root = new TreeNode(stoi(values[0]));
        queue<TreeNode*> q;
        q.push(root);
        
        for(int i=1; i<values.size(); i++) {
            TreeNode* temp = q.front();
            q.pop();
            if(values[i] != "n") {
                temp->left = new TreeNode(stoi(values[i]));
                q.push(temp->left);
            }
            if(++i != values.size() && values[i] != "n") {
                temp->right = new TreeNode(stoi(values[i]));
                q.push(temp->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
