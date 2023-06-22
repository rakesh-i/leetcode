/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int helper(queue<TreeNode*> &l){
        queue<TreeNode*> k;
        while(!l.empty()){
            if(l.front()->left==NULL&&l.front()->right==NULL){
                return 1;
            }
            if(l.front()->left){
                k.push(l.front()->left);
            }
            if(l.front()->right){
                k.push(l.front()->right);
            }
            l.pop();
        }
        l.swap(k);
        return 0;
    }

    int level(TreeNode *root){
        TreeNode *temp = root;
        queue<TreeNode*> l;
        l.push(temp);
        int count = 0;
        while(!l.empty()){
            count++;
            if(helper(l)==1){
                break;
            }
        }
        return count;
    }
    int minDepth(TreeNode* root) {
        TreeNode *temp = root;
        if(root==NULL){
            return 0;
        }
        return (level(temp));
    }
};
// @lc code=end

