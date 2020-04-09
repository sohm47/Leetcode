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
    // Time: O(N), Space: O(1)
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *slowPointer=head, *fastPointer=head->next;
        while(fastPointer && fastPointer->next) {
            slowPointer=slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        
        if(!fastPointer)
            return slowPointer;
        
        return slowPointer->next;
    }
};
