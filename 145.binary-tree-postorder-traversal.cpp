/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
        helper(head->left, a);
        
        helper(head->right, a);
        a.push_back(head->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *temp = root;
        helper(temp, res);
        return res;
    }
};
// @lc code=end

