/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
    unordered_map<int, vector<TreeNode*>> m;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>res;
        if(m.find(n)!=m.end()){
            return m[n];
        }
        if(n==0){
            return {};
        }
        if(n==1){
            TreeNode *temp = new TreeNode(0);
            res.push_back(temp);
            return {temp};
        }
        for(int i=1; i<n; i++){
            vector<TreeNode*> l = allPossibleFBT(i);
            vector<TreeNode*> r = allPossibleFBT(n-i-1);
            for(auto x:l){
                for(auto y:r){
                    TreeNode*root = new TreeNode(0);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }
            }
            m[n] = res;
        }
        return res; 
    }
};
// @lc code=end

