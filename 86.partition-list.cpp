/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    void insert(ListNode** root,int x, ListNode **e){
        ListNode *temp = new ListNode();
        temp->val = x;
        temp->next=  NULL;
        temp->next=NULL;
        if(*root==NULL){
            *root = temp;
            *e = temp;
            return;
        }
        ListNode *t1 = *root;
        while(t1->next){
            t1 = t1->next;
        }
        t1->next = temp;
        *e =  temp;
        return;

    }
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp = head;
        ListNode *r1 = NULL;
        ListNode *r2 = NULL;
        ListNode *r1e = NULL;
        ListNode *r2e = NULL;
        while(temp){
            if(temp->val<x){
                insert(&r1,temp->val, &r1e );
                temp = temp->next;
            }
            else{
                insert(&r2,temp->val, &r2e);
                temp = temp->next;
            }
        }
        if(r1&&r2){
            r1e->next = r2;
            return r1;
        }
        else if(!r1){
            return  r2;
        }
        else{
            return r1;
        }
    }
};
// @lc code=end

