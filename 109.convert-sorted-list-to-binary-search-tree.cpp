/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* helper(vector<int> &n, int h, int l){
        if(l<=h){
            int mid = l+(h-l)/2;
            TreeNode *root = new TreeNode(n[mid]);
            root->left = helper(n, mid-1, l);
            root->right = helper(n, h, mid+1);
            return root;
        }
        return NULL;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *temp = head;
        vector<int> nums;
        while(!temp==NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        return helper(nums, nums.size()-1, 0);
    }
};
// @lc code=end

