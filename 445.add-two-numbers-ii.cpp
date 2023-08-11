/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> k1, k2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1&&temp2){
            k1.push_back(temp1->val);
            k2.push_back(temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            k1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2){
            k2.push_back(temp2->val);
            temp2 = temp2->next;
        }
        int n1 = k1.size()-1;
        int n2 = k2.size()-1;
        ListNode *res = new ListNode(0);
        res->next = NULL;
        int carry = 0;
        while(n1!=-1&&n2!=-1){
            int x = k1[n1--]+k2[n2--]+carry;
            ListNode *temp = new ListNode();
            temp->next = NULL;
            if(x>9){
                temp->val = x%10;
                carry = x/10;
                temp->next = res->next;
                res->next = temp;
            }
            else{
                temp->val = x;
                carry = 0;
                temp->next = res->next;
                res->next = temp; 
            }
        }

        while(n1!=-1){
            int x = k1[n1--]+carry;
            ListNode *temp = new ListNode();
            temp->next = NULL;
            if(x>9){
                temp->val = x%10;
                carry = x/10;
                temp->next = res->next;
                res->next = temp;
            }
            else{
                temp->val = x;
                carry = 0;
                temp->next = res->next;
                res->next = temp; 
            }
        }
        while(n2!=-1){
            int x = k2[n2--]+carry;
            ListNode *temp = new ListNode();
            temp->next = NULL;
            if(x>9){
                temp->val = x%10;
                carry = x/10;
                temp->next = res->next;
                res->next = temp;
            }
            else{
                temp->val = x;
                carry = 0;
                temp->next = res->next;
                res->next = temp; 
            }
        }
        if(carry){
            ListNode *temp = new ListNode();
            temp->next = NULL;
            temp->val = carry;
            temp->next = res->next;
            res->next = temp;

        }
        return res->next;
    }
};
// @lc code=end

