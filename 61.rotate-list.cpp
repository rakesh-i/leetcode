/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* helper(ListNode *head){
        ListNode *temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        ListNode *root = temp->next;
        temp->next = NULL;
        root->next = head;
        return root;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp = head;
        long count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        if(count<=1){
            return head;
        }
        long rotate = (k>count)?k%count:k;
        for(int i=0; i<rotate; i++){
            head = helper(head);
        }
        return head;
        
    }
};
// @lc code=end

