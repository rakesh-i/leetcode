/*
 * @lc app=leetcode id=19 lang=csharp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        ListNode temp = new ListNode();
        temp = head;
        ListNode prev = new ListNode();
        ListNode next = new ListNode();
        prev = temp;
        int count = 0;
        while(temp!=null){
            temp = temp.next;
            count++;
            if(count>n+1){
                prev = prev.next;
            }
        }
        if(count==1){
            return null;
        }
        if(n==count){
            return head.next;
        }
        prev.next = prev.next.next;
        return head;
        

    }
}
// @lc code=end

