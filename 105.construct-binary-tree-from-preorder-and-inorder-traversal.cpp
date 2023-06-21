/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int preIndex = 0;
    TreeNode* build(vector<int> &in, vector<int>&pre, int s, int e, unordered_map<int, 
    int> &a){
        if(s>e){
            return NULL;
        }
        int curr = pre[preIndex++];
        TreeNode* temp = new TreeNode();
        temp->val = curr;
        temp->right = NULL;
        temp->left = NULL;
        if(s==e){
            return temp;
        }
        int inIndex = a[curr];
        temp->left = build(in, pre, s, inIndex-1, a);
        temp->right = build(in, pre, inIndex+1, e, a);
        
        return temp;
    }

    TreeNode* mp(vector<int> &in, vector<int> &pre){
        unordered_map<int, int> a;
        for(int i=0; i<in.size(); i++){
            a[in[i]]=i;
        }
        return build(in, pre, 0, in.size()-1, a); 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = NULL;
        res = mp(inorder, preorder);
        preIndex = 0;
        return res;
    }
};
// @lc code=end

