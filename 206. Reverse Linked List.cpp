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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *prev = nullptr;
        while(head) {
            ListNode *temp = head;
            head = head->next;
            
            temp->next = prev;
            prev = temp;
        }
        
        return prev;
    }
};
