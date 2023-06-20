/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    void helper(TreeNode *head, vector<int> &a ){
        if(head==NULL){
            return;
        }
        a.push_back(head->val);
        helper(head->left, a);
        helper(head->right, a);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *temp = root;
        helper(temp, res);
        return res;
    }
};
// @lc code=end

