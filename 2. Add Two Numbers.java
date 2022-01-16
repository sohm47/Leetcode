/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    // M = length of l1, N = length of l2
    // Time: O(max(M, N)), Space: O(max(M, N))
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode l3 = new ListNode();
        ListNode head = l3;
        
        while(l1 != null || l2 != null || carry != 0) {
            int sum = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carry;
            carry = sum/10;
            
            l3.next = new ListNode(sum%10);
            l3 = l3.next;
            
            if(l1 != null) 
                l1 = l1.next;
            if(l2 != null)
                l2 = l2.next;
        }
        
        return head.next;
    }
}
