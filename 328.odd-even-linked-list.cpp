/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *t1 = new ListNode(0);
        ListNode *t2 = new ListNode(0);
        ListNode *d1 = t1;
        ListNode *d2 = t2;
        int s = 0;
        while(temp){
            if(s==0){
                d1->next = temp;
                d1 = temp;
                temp = temp->next;
                s = 1;
            }   
            else{
                d2->next = temp;
                d2 = temp;
                temp = temp->next;
                s = 0;
            }
        } 
        d2->next = NULL;
        d1->next = t2->next;
        return t1->next;
    }
};
// @lc code=end

