/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:    
    Node* flatten(Node* head) {
        Node *curr = head;
        while(curr) {
            if(curr->child) {
                Node *child = curr->child, *prevchild;
                while(child) {
                    prevchild = child;
                    child = child->next;
                }
                prevchild->next = curr->next;
                if(curr->next)
                    curr->next->prev = prevchild;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            curr = curr->next;
        }
        
        return head;
    }
};
