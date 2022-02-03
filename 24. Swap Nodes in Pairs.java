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
    // Time: O(N), Space: O(1) 
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)
            return head;
        
        ListNode curr = head, prev = new ListNode();
        prev.next = head;
        head = curr.next;
        
        while(curr != null && curr.next != null) {
            prev.next = curr.next;
            curr.next = curr.next.next;
            prev.next.next = curr;
            prev = curr;
            curr = prev.next;
        }
        
        return head;
    }
}
