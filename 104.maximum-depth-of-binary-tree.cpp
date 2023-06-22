/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int helper(TreeNode *head){
        if(head==NULL){
            return 0;
        }
        else{
            int ldepth = helper(head->left);
            int rdepth = helper(head->right);

            return(ldepth>rdepth)?ldepth+1:rdepth+1;
        }
    }

    int maxDepth(TreeNode* root) {
        TreeNode *temp = root;
        return helper(temp);
    }
};
// @lc code=end

