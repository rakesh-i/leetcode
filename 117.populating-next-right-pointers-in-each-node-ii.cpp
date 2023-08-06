/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
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
        queue<Node*> k;
        vector<Node*> v;
        while(!l.empty()){
            if(l.front()->left){
                k.push(l.front()->left);
                v.push_back(l.front()->left);
            }
            if(l.front()->right){
                k.push(l.front()->right);
                v.push_back(l.front()->right);
            }
            l.pop();
        }
        int n = v.size();
        if(n==1){
            v[0]->next=NULL;
        }
        else if(n>1){
            for(int i=1; i<n; i++){
                v[i-1]->next = v[i];
            }
            v[n-1]->next=NULL;
        }
        l.swap(k);
    }
    Node* connect(Node* root) {
        queue<Node*> l;
        if(!root){
            return root;
        }
        l.push(root);
        while(!l.empty()){
            bfs(l);
        }
        return root;
    }
};
// @lc code=end

