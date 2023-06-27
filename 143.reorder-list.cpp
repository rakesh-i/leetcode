/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
       deque<ListNode*> a;
       ListNode *temp =  head;
       int count =0;
       while(temp){
        a.push_back(temp);
        temp = temp->next;
        count++;
       } 
       ListNode *back = NULL;
       if(count>1){
            while(!a.empty()){
                if(back){
                    back->next = a.front();
                }
                a.front()->next = a.back();
                back = a.back();
                if(!a.empty()){
                    a.pop_back();
                    if(!a.empty()){
                        a.pop_front();
                    }
                }
            }
            back->next = NULL;
       }
       
    }
};
// @lc code=end

