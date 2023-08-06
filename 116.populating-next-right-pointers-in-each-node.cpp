/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(queue<Node*> &l){
        queue<Node*>k;
        vector<Node*> v;
        while(!l.empty()){
            if(l.front()->right||l.front()->left){
                k.push(l.front()->left);
                k.push(l.front()->right);
                v.push_back(l.front()->left);
                v.push_back(l.front()->right);
            }
            l.pop();
        }
        if(v.size()>1){
            for(int i=1; i<v.size(); i++){
                v[i-1]->next = v[i];
            }
            v[v.size()-1]->next = NULL;
        }
        l.swap(k);

    }
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        if(!root->left){
            root->next = NULL;
            return root;
        }
        queue<Node*> l;
        l.push(root->left);
        root->left->next = root->right;
        root->right->next = NULL;
        l.push(root->right);
        while(!l.empty()){
            bfs(l);
        }
        return root;
    }
};
// @lc code=end

