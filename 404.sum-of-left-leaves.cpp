/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sum = 0;
    bool isleft(TreeNode *node){
        if(node==NULL){
            return false;
        }
        if(node->left==NULL&&node->right==NULL){
            return true;
        }
        return false;
    }
    void helper(TreeNode* head){
        if(head==NULL){
            return;
        }
        if(isleft(head->left)){
            sum+=head->left->val;
        }
        helper(head->left);
        helper(head->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return sum;
    }
};
// @lc code=end

