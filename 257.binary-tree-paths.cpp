/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void helper(TreeNode *head, string t, vector<string> &s){
        if(!head->right&&!head->left){
            s.push_back(t);
            return;
        }
        if(head->left){
            helper(head->left, t+"->"+to_string(head->left->val), s);
            }
        if(head->right){
            helper(head->right, t+"->"+to_string(head->right->val), s);
            }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> s;
        if(!root){
            return s;
        }
        
        helper(root, to_string(root->val), s);
        return s;
    }
};
// @lc code=end

