/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void lca(TreeNode* head, TreeNode** l, int x, int y, int flag){
        if(flag==1){
            return;
        }
        if(head->val==x||head->val==y){
            *l = head;
            flag =1;
            return;
        }
        if(head->val>x && head->val<y){
            *l = head;
            flag =1;
            return;
        }
        if(x<head->val&&y<head->val){
            lca(head->left, l, x, y,flag);
        }
        if(x>head->val&&y>head->val){
            lca(head->right, l, x, y, flag);
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *l = new TreeNode();
        l = NULL;
        int x = min(p->val, q->val);
        int y = max(p->val, q->val);
        lca(root,&l, x, y, 0);
        return l;
    }
};
// @lc code=end

