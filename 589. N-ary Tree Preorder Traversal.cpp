/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {  
public:
    vector<int> preorder(Node* root) {
        if(root==NULL)
            return {};
        
        vector<int> ret;
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty()) {
            Node* temp = s.top();
            s.pop();
            ret.push_back(temp->val);
            for(int i=temp->children.size()-1; i>-1; i--)
                if(temp->children[i]) 
                    s.push(temp->children[i]);
        }
        
        return ret;
    }
};
