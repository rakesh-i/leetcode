/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    vector<int> a;
    void inorder(TreeNode *head){
        if(head==NULL){
            return;
        }
        inorder(head->left);
        a.push_back(head->val);
        inorder(head->right);

    }

    bool isValidBST(TreeNode* root) {
        TreeNode *temp = root;
        inorder(temp);
        for(int i=1; i<a.size(); i++){
            if(a[i-1]>=a[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

