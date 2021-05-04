/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        int size1 = 0, size2 = 0;
        
        size1 = getSize(headA);
        size2 = getSize(headB);
        
        int diff = Math.abs(size1 - size2);
        
        if(size1>size2){
            for(int i=0;i<diff;i++){
                headA = headA.next;
            }
        } else{
            for(int i=0;i<diff;i++){
                headB = headB.next;
            }
        }
        
        while(headA!=null || headB!=null){
            if(headA == headB){
                return headA;
            }
            headA=headA.next;
            headB=headB.next;
        }
        return null;
        
    }
    
    public int getSize(ListNode head){
        int count=0;
        while(head!=null){
            count++;
            head = head.next;
        }
        
        return count;
    }
}