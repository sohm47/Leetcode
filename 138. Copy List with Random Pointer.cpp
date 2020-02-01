/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        Node *newHead = new Node(0);
        Node *newCurr = newHead, *curr = head;
        unordered_map<Node*, Node*> hash;
        
        while(curr) {
            newCurr->next = new Node(curr->val);
            newCurr = newCurr->next;
            hash[curr] = newCurr;
            curr=curr->next;
        }
        
        curr = head;
        while(curr) {
            if(curr->random) {
                hash[curr]->random = hash[curr->random];
            }
            curr = curr->next;
        }
        
        return newHead->next;
    }
};
