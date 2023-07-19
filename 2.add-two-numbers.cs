/*
 * @lc app=leetcode id=2 lang=csharp
 *
 * [2] Add Two Numbers
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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        int carry = 0;
        while(l1!=null&&l2!=null){
            int x = l1.val+l2.val+carry;
            if(x>9){
                carry = x/10;
                ListNode t = new ListNode(x%10);
                temp.next = t;
                temp = t;
                l1 = l1.next;
                l2 = l2.next;
            }
            else{
                carry = 0;
                ListNode t = new ListNode(x);
                temp.next = t;
                temp = t;
                l1 = l1.next;
                l2 = l2.next;
            }
        }   
        while(l1!=null){
            int x = l1.val+carry;
            if(x>9){
                carry = x/10;
                ListNode t = new ListNode(x%10);
                temp.next = t;
                temp = t;
                l1 = l1.next;
            }
            else{
                carry = 0;
                ListNode t = new ListNode(x);
                temp.next = t;
                temp = t;
                l1 = l1.next;
            }
        }
        while(l2!=null){
            int x = l2.val+carry;
            if(x>9){
                carry = x/10;
                ListNode t = new ListNode(x%10);
                temp.next = t;
                temp = t;
                l2 = l2.next;
            }
            else{
                carry = 0;
                ListNode t = new ListNode(x);
                temp.next = t;
                temp = t;
                l2 = l2.next;
            }
        }
        if(carry>0){
            ListNode t = new ListNode(carry);
            temp.next = t;
            temp = t;
        }
        return dummy.next;
    }
}
// @lc code=end

