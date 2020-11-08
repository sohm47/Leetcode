/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *curr = head->next;
        vector<int> sums{head->val};
        while(curr != nullptr) {
            sums.push_back(sums.back()+curr->val);
            curr = curr->next;
        }
        
        curr = head;
        int i = sums.size()-1;
        while(i >= 0){
            if(sums[i] == 0) {
                int j=0;
                while(j++ <= i)
                    curr = curr->next;
                head = curr;
                break;
            }
            --i;
        }
        ++i;
        
        while(i < sums.size()) {
            ListNode *temp = curr;
            for(int j=sums.size()-1; j>i; j--) {
                if(sums[j] == sums[i]) {
                    while(i++ < j)
                        curr = curr->next;
                    --i;
                    break;
                }
            }
            curr = curr->next;
            temp->next = curr;
            ++i;
        }
        
        return head;
    }
};
