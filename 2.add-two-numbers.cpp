/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *temp = new ListNode();
        dummy = temp;
        int carry = 0;
        while(l1&&l2){
            int x = l1->val+l2->val+carry;
            ListNode *s = new ListNode();
            if(x>9){
                carry = x/10;
                s->val = x%10;
                temp->next = s;
                temp = s;
                l1 = l1->next;
                l2 = l2->next;
            }
            else{
                carry = x/10;
                s->val = x%10;
                temp->next = s;
                temp = s;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        while(l1){
            int x = l1->val+carry;
            ListNode *s = new ListNode();
            if(x>9){
                carry = x/10;
                s->val = x%10;
                temp->next = s;
                temp = s;
                l1 = l1->next;
            }
            else{
                carry = x/10;
                s->val = x%10;
                temp->next = s;
                temp = s;
                l1 = l1->next;
            }
        }
        while(l2){
            int x = l2->val+carry;
            ListNode *s = new ListNode();
            if(x>9){
                carry = x/10;
                s->val = x%10;
                temp->next = s;
                temp = s;
                l2 = l2->next;
            }
            else{
                carry = x/10;
                s->val = x%10;
                temp->next = s;
                temp = s;
                l2 = l2->next;
            }
        }
        if(carry){
            ListNode *s = new ListNode();
            s->val = carry;
            temp->next = s;
        }
        return dummy->next;

    }
};
// @lc code=end

