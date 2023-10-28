/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    int find_min(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp->left)
        {
            temp = temp->left;
        }
        return temp->val;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return NULL;
        }
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                return root->right;
            }
            else if (root->right == NULL)
            {
                return root->left;
            }
            root->val = find_min(root->right);
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};
// @lc code=end
