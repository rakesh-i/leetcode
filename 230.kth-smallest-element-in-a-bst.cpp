/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    void helper(TreeNode* root, vector<int> &a){
        if(root == NULL){
            return;
        }
        helper(root->left, a);
        a.push_back(root->val);
        helper(root->right, a);        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        helper(root, a);
        return a[k-1];
    }
};
// @lc code=end

