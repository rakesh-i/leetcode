/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *temp= curr->next;
        ListNode *root = temp;
        if(!temp->next){
            temp->next = curr;
            curr->next=NULL;
            return root;
        }
        ListNode *next = temp->next; 
        while(next){
            curr->next = next;
            temp->next = curr;
            if(prev==NULL){
                prev = curr;
                curr = next;
                temp = curr->next;
                if(!temp){
                    return root;
                }
                next = temp->next;
            }
            else{
                prev->next = temp;
                prev = curr;
                curr = next;
                temp = curr->next;
                if(!temp){
                    return root;
                }
                next = temp->next;
            }
        }
        if(!temp){
            return root;
        }
        temp->next = curr;
        curr->next = NULL;
        prev->next = temp;
        
        return root;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        return helper(head);

    }
};
// @lc code=end

