/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<pair<ListNode*, ListNode*>> a;
        ListNode *temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        temp = head;
        ListNode *prev = NULL;
        ListNode *cur = temp;
        ListNode *right = NULL;
        for(int i=0; i<n/k; i++){
            int count = 0;
            ListNode *s = cur;
            while(count<k){
                right = cur->next;
                cur->next = prev;
                prev = cur;
                cur = right;
                count++;
            }
            a.push_back({s, prev});
            prev = NULL;
            right = NULL;
        }
        int j=0;
        for(int i=1;i<a.size(); i++){
            a[i-1].first->next = a[i].second;
            j=i;
        }
        if(cur){
            a[j].first->next = cur;
        }
        return a[0].second;
    }
};
// @lc code=end

