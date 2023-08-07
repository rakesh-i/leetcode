/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    void dfs(TreeNode *head, int n, int &s, int u){
        if(!head){
            return;
        }
        n =n*u + head->val;
        if(!head->left&&!head->right){
            s += n;
            u = (u/10==0)?1:u/10;
            return;
        }
        dfs(head->left, n, s, 10);
        dfs(head->right, n, s, 10);
        n = n/10;

    }
    int sumNumbers(TreeNode* root) {
        int s = 0;
        dfs(root, 0, s, 1);
        return s;
    }
};
// @lc code=end

