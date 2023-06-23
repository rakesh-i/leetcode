/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
public:
    void inorder(TreeNode *temp, queue<int> &a){
        if(temp==NULL){
            return;
        }
        inorder(temp->left, a);
        a.push(temp->val);
        inorder(temp->right,a);
    }

    BSTIterator(TreeNode* root) {
      head = root;  
      inorder(head, a);
    }
    
    int next() {
        int x = a.front();
        a.pop();
        return x;
    }
    
    bool hasNext() {
        if(!a.empty()){
            return true;
        }
        return false;
    }
private:
    TreeNode *head;
    queue<int> a;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

