/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    void helper(queue<TreeNode*> &l, vector<int> &a){
        queue<TreeNode*> k;
        while(!l.empty()){
            a.push_back(l.front()->val);
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> b;
        queue<TreeNode*> list;
        TreeNode* temp = root;
        if(temp==NULL){
            return {};
        }
        list.push(temp);
        int dir = 1;
        while(!list.empty()){
            vector<int> a;
            helper(list, a);
            if(dir==0){
                reverse(a.begin(), a.end());
            }
            b.push_back(a);
            dir = (dir==1)?0:1;
        }
        return b;
    }
};
// @lc code=end

