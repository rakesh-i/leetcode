/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    void helper(queue<TreeNode*>&l, vector<int> &a){
        queue<TreeNode*> k;
        int x = -101;
        while(!l.empty()){
            x = l.front()->val;
            if(l.front()->left){
                k.push(l.front()->left);
            }
            if(l.front()->right){
                k.push(l.front()->right);
            }
            l.pop();
        }
        if(x>-101){
            a.push_back(x);
        }
        l.swap(k);
    }

    void level(TreeNode *head, vector<int> &a){
        queue<TreeNode*> l;
        l.push(head);
        while(!l.empty()){
            helper(l, a);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> a;
        level(root, a);
        return a;
    }
};
// @lc code=end

