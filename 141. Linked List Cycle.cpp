/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        
        ListNode* temp = new ListNode(0);
        temp->next = head;        
              
	while(head && head->next) {
            if(head == temp)
                return true;
            head = head->next->next;
            temp = temp->next;
        }
        
        return false;
    }
};
