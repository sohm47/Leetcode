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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode * curr=head, *prev = NULL;
        while(curr) {
            if(curr->val == val) {
                if(prev)
                    prev->next = curr->next;       
                else
                    head = curr->next;
            }
            else
                prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};
