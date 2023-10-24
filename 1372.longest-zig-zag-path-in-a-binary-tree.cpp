/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
class Solution
{
public:
    int mx = 0;
    void helper(TreeNode *root, int dir, int count)
    {
        if (!root)
        {
            mx = max(mx, count);
            return;
        }
        if (dir)
        {
            helper(root->left, 0, count + 1);
            helper(root->right, 1, 0);
        }
        else
        {
            helper(root->left, 0, 0);
            helper(root->right, 1, count + 1);
        }
    }
    int longestZigZag(TreeNode *root)
    {
        helper(root, 0, -1);
        helper(root, 1, -1);
        return mx;
    }
};
// @lc code=end
