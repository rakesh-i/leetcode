/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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

    void helper(TreeNode* head, vector<int> &a, vector<TreeNode*> &b){
        if(head==NULL){
            return;
        }
        helper(head->left, a, b);
        a.push_back(head->val);
        b.push_back(head);
        helper(head->right, a, b);
    }

    void recoverTree(TreeNode* root) {
        int top = root->val;
        vector<int> t;
        TreeNode *temp = root;
        vector<int> a, b;
        vector<TreeNode*> c;
        helper(temp, a, c);
        b=a;
        sort(b.begin(), b.end());
        for(int i=0; i<a.size(); i++){
            if(b[i]!=a[i]){
                t.push_back(i);
            }
        }
        int tag1 = t[0];
        int tag2 = t[1];
        int x = c[tag1]->val;
        c[tag1]->val = c[tag2]->val;
        c[tag2]->val = x;

    }
};
// @lc code=end

