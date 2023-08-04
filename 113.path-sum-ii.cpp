/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void dfs(TreeNode *head, int n, int s, vector<int> cur, vector<vector<int>> &res){
        if(!head){
            return;
        }
        cur.push_back(head->val);
        n = n+head->val;
        if(!head->left&&!head->right){
            if(n==s){
                res.push_back(cur);
            }
        }
        dfs(head->left, n, s, cur, res);
        dfs(head->right, n, s, cur, res);
        n = n - cur.back();
        cur.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {   
       vector<vector<int>> res;
       vector<int> cur;
       dfs(root, 0, targetSum, cur, res);
       return res;
    }
};
// @lc code=end

