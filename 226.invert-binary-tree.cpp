/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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

    void helper(queue<TreeNode*> &l){
        queue<TreeNode*> k;
        while(!l.empty()){
            TreeNode *temp = l.front()->left;
            l.front()->left = l.front()->right;
            l.front()->right = temp;
            if(l.front()->left){
                k.push(l.front()->left);
            }
            if(l.front()->right){
                k.push(l.front()->right);
            }
            l.pop();
        }
        l.swap(k);
    }

    void level(TreeNode *head){
        queue<TreeNode*> l;
        l.push(head);
        while(!l.empty()){
            helper(l);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode *temp = root;
        if(root==NULL){
            return root;
        }
        level(temp);
        return root;
    }
};
// @lc code=end

