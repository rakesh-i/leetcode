/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    void helper(TreeNode* root, int *a){
        if(root==NULL){
            return;
        }
        helper(root->left, a);
        *a = *a +1;
        helper(root->right, a);
    }

    int countNodes(TreeNode* root) {
       int a = 0;
       helper(root, &a);
       return a; 
    }  
};
// @lc code=end

