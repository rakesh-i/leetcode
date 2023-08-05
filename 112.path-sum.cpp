/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    void dfs(TreeNode* head, int n, int s, int* res){
        if(!head){
            return;
        }
        s += head->val;
        if(!head->left&&!head->right){
            if(s==n){
                *res = 1;
            }
            return;
        }
        
        dfs(head->left, n, s, res);
        dfs(head->right, n, s, res);
        s = s-head->val;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int res = 0;
        dfs(root, targetSum, 0, &res);
        if(res==1){
            return true;
        }
        return false;
    }
};
// @lc code=end

