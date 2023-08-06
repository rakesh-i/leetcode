/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int dfs(TreeNode* head, int &ans){
        if(!head){
            return 0;
        }
        if(!head->left&&!head->right){
            ans = max(ans, head->val);
            return head->val;
        }
        int left = dfs(head->left, ans);
        int right = dfs(head->right, ans);
        int currmax = max(head->val, max(left+head->val, right+head->val));
        ans = max(currmax, max(head->val+left+right, ans));
        return currmax;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int a = dfs(root, ans);
        return ans;
    }
};
// @lc code=end

