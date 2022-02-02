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
    // Time: O(M+N), Space: O(1)
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode list3 = new ListNode();
        ListNode head = list3;
        
        while(list1 != null && list2 != null) {
            if(list1.val < list2.val) {
                list3.next = new ListNode(list1.val);
                list1 = list1.next;
            }
            else {
                list3.next = new ListNode(list2.val);
                list2 = list2.next;
            }
            list3 = list3.next;
        }
        
        list3.next = (list1 == null ? list2 : list1);
        
        return head.next;
    }
}
