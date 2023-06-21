/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    int postIndex = 0;
    
    TreeNode* build(vector<int> &in, vector<int> &post, int s, int e, unordered_map<int,
    int> &a){
        if(s>e){
            return NULL;
        }
        int curr = post[postIndex++];
        TreeNode* temp = new TreeNode();
        temp->val = curr;
        temp->right = NULL;
        temp->left = NULL;
        if(s==e){
            return temp;
        }
        int inIndex = a[curr];
        
        temp->right = build(in, post, inIndex+1, e, a);
        temp->left = build(in, post, s, inIndex-1, a);
        return temp;
    }

    TreeNode *mp(vector<int> &in, vector<int> &post){
        unordered_map<int, int> a;
        for(int i=0; i<in.size(); i++){
            a[in[i]] = i;
        }
        return build(in, post, 0, in.size()-1, a);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        TreeNode *res = NULL;
        res = mp(inorder, postorder);
        postIndex = 0;
        return res;
        
    }
};
// @lc code=end

