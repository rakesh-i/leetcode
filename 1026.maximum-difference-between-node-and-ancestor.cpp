/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
    int helper(TreeNode *root, int mx, int mn)
    {
        if (root == NULL)
        {
            return mx - mn;
        }
        return max(helper(root->left, max(root->val, mx), min(mn, root->val)),
                   helper(root->right, max(mx, root->val), min(root->val, mn)));
    }
    int maxAncestorDiff(TreeNode *root)
    {
        return helper(root, 0, 100000);
    }
};
// @lc code=end
