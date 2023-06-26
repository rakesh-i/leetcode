/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next =head;
        ListNode *cur = dummy;
        int d;
        while(cur->next&&cur->next->next){
            if(cur->next->val==cur->next->next->val){
                d = cur->next->val;
                while(cur->next&&cur->next->val==d){
                    cur->next = cur->next->next;
                }
            }
            else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

