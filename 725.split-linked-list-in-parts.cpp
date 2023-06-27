/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        int n=0;
        n = count/k;
        temp = head;
        int r = count%k;
        vector<ListNode*> a;
        while(temp){
            ListNode *t = temp;
            ListNode *x = t;
            int b = (r>0)?n+1:n;
            while(b-1&&t){
                t = t->next;
                b--;
            }
            if(t){
                temp = t->next;
                t->next = NULL;
                a.push_back(x);
                r--;
            }
            else{
                break;
            }
        }
        while(a.size()<k){
            a.push_back(NULL);
        }
        return a;
        
    }
};
// @lc code=end

