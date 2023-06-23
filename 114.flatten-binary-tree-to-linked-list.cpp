/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start
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

    void insert(TreeNode *head, TreeNode *temp){
        temp->right = NULL;
        temp->left = NULL;
        while(head->right!=NULL){
            head = head->right;
        }
        head->right = temp;
    }

    void helper(TreeNode *head, vector<TreeNode*> &a){
        if(head ==NULL){
            return;
        }
        a.push_back(head);
        helper(head->left, a);
        helper(head->right, a);
    }

    void flatten(TreeNode* root) {
        TreeNode *temp = root;
        if(root==NULL){
            return;
        }
        vector<TreeNode*> a;
        helper(temp, a);
        root->right = NULL;
        root->left = NULL;
        for(int i=1; i<a.size(); i++){
            insert(root, a[i]);
        }
    }
};
// @lc code=end

