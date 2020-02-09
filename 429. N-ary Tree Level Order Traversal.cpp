/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for(int i=0; i<size; i++) {
                Node *temp = q.front();
                q.pop();
                level[i] = temp->val;
                for(int j=0; j<temp->children.size(); j++) {
                    q.push(temp->children[j]);
                }
            }
            
            res.push_back(level);
        }
        
        return res;
    }
};
