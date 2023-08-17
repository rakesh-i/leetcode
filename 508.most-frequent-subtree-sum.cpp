/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
    int sum = 0;
    unordered_map<int, int> m;
    void  helper(TreeNode* head){
        if(head==NULL){
            return;
        }
        helper(head->left); 
        inorder(head);
        m[sum]++;
        sum = 0;
        helper(head->right);
    }
    void inorder(TreeNode*head){
        if(head==NULL){
            return;
        }
        inorder(head->left);
        sum += head->val;
        inorder(head->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        TreeNode* temp = root;
        helper(temp);
        int max = 0;
        map<int, vector<int>> mp;
        for(auto i:m){
            mp[i.second].push_back(i.first);
        }
        vector<int> res;
        auto i = mp.rbegin();
        for(int j=0; j<i->second.size(); j++){
            res.push_back(i->second[j]);
        }
            
        return res;
    }
};
// @lc code=end

