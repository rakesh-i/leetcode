/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    void insert(ListNode **head, int x){
        ListNode *temp = new ListNode();
        temp->val = x;
        temp->next = NULL;
        if(*head == NULL){
            *head = temp; 
            return;
        }
        ListNode *temp1 = *head;
        while(temp1->next){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    ListNode* insertionSortList(ListNode* head) {
        vector<int> a;
        ListNode *temp = head;
        while(temp){
            a.push_back(temp->val);
            temp = temp->next;
        }
        sort(a.begin(), a.end());
        temp = NULL;
        for(int i=0; i<a.size(); i++){
            insert(&temp, a[i]);
        }
        return temp;
    }
};
// @lc code=end

