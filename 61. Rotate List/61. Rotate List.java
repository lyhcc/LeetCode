/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        int len = 0;
        ListNode p = head,tail = null;
        while(p!=null){
            len++;
            if(p.next==null){
                tail = p;
            }
            p=p.next;
            
        }
        if(len == 0) return null;
        
        k = k % len;
        if(len == 1|| k == 0) return head;
        ListNode pre = null;
        p = head;
        int i = len - k;
        while(p!=null&& i>0){
            pre = p;
            p=p.next;
            i--;
        }
        pre.next = null;
        tail.next = head;
        return p;
    }
}
