/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return head;
        }
        map<ListNode*, int> m;
        while(head){
            m[head]++;
            if(m[head]>1){
                return head;
            }
            head = head->next;
        }
        return head;
    }
};
// @lc code=end

