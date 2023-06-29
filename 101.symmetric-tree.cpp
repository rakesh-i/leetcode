/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool helper(TreeNode* r, TreeNode* l){
        if(r==NULL&&l==NULL){
            return true;
        }
        else if(r==NULL||l==NULL){
            return false;
        }
        else if(r->val!=l->val){
            return false;
        }
        
        return helper(r->right, l->left)&&helper(r->left, l->right);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->right, root->left);
    }
};
// @lc code=end

