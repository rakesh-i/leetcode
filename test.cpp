#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
};

void insert(Node **root, int n){
    Node *temp = new Node();
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    Node *head = *root;
    Node *curr = *root;
    Node *prev = new Node();
    if(head==NULL){
        *root = temp;
        return;
    }
    while(curr!=NULL){
        if(curr->data<n){
            prev  = curr;
            curr = curr->right;
        }
        else{
            prev = curr;
            curr = curr->left;
        }
    }
    if(prev->data>n){
        prev->left = temp;
    }
    else{
        prev->right = temp;
    }

}

Node* search(Node **root, int n){
    Node *curr = *root;
    Node *prev = new Node();
    while(curr!=NULL){
        if(curr->data==n){
            return prev;
        }
        else if(curr->data<n){
            prev = curr;
            curr = curr->right;
        }
        else{
            prev = curr;
            curr = curr->left;
        }
    }
    return NULL;
}

Node* min(Node **root){
    Node *curr = *root;
    Node *prev = new Node();
    while(curr!=NULL){
        prev = curr;
        curr = curr->left;
    }
    return prev;
}

Node* max(Node **root){
    Node *curr = *root;
    Node *prev = new Node();
    while(curr!=NULL){
        prev  = curr;
        curr = curr->right;
    }
    return prev;
}

int del(Node **root, int n){
    Node *head = *root;
    Node *prev = new Node();
    if(head->data==n){
        *root = NULL;
        return 1;
    }
    prev = search(&head, n);
    if(prev==NULL){
        return -1;     
    }
    Node *curr = (prev->left->data==n)?prev->left:prev->right;
    if(curr->left==NULL&&curr->right==NULL){
        if(prev->left==curr){
            prev->left=NULL;
            free(curr);
            return 1;
        }
        else{
            prev->right = NULL;
            free(curr);
            return 1;
        }

    }
    else if(curr->left&&curr->right){
        Node *t1= curr;
        Node *h = *root;
        Node *a = min(&t1);
        int val = a->data;
        del(&h, val);
        curr->data = val;
        return 1;

        
    }
    else{
        if(prev->left==curr){
            prev->left = (curr->left)?curr->left:curr->right;
            free(curr);
            return 1;
        }
        else{
            prev->right = (curr->left)?curr->left:curr->right;
            free(curr);
            return 1;
        }
        
    }
    
    return -1;
}

void inorder(Node *head){
    if(head==NULL){
        return;
    }
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}

void preorder(Node *head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}

void postorder(Node *head){
    if(head==NULL){
        return;
    }
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}

void helper(Node *head, queue<Node*> &l, vector<int> &a){
    queue<Node*> k;
    while(!l.empty()){
        a.push_back(l.front()->data);
        
        if(l.front()->left){
            k.push(l.front()->left);
        }
        if(l.front()->right){
            k.push(l.front()->right);
        }
        l.pop();
    }
    l.swap(k);

    
}

void levelorder(Node **root){
    queue<Node*> list;
    Node* head = *root;
    list.push(head);
    vector<vector<int>> b;
    while(!list.empty()){
        vector<int> a;
        helper(head, list, a);
        b.push_back(a);
    }
    for(int i=0; i<b.size(); i++){
        for(int j=0; j<b[i].size(); j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

}

Node* build(vector<int> &in, vector<int> &pre, int s, int e, unordered_map<int,int> &a){
        static int preIndex = 0;
        //There is only one child for the parent 
        if(s>e){
            return NULL;
        }
        int curr = pre[preIndex++];
        Node* temp = new Node();
        temp->data = curr;
        temp->left=NULL;
        temp->right =NULL;
        //No child for the parent
        if(s==e){
            return temp;
        }
        int inIndex = a[curr];
        cout<<s<<" "<<e<<" "<<" "<<inIndex<<" "<<curr<<endl;
        temp->left = build(in, pre, s, inIndex-1, a);
        temp->right = build(in, pre, inIndex+1, e, a);
        return temp;

}

Node* mp(vector<int> &in, vector<int> &pre){
    unordered_map<int, int> a;
    for(int i=0; i<in.size(); i++){
        a[in[i]] = i;
    }
    return (build( in, pre, 0, in.size()-1, a));
}

void print(Node **root){
    Node *temp = *root;
    inorder(temp);
    cout<<endl;
    preorder(temp);
    // cout<<endl;
    // postorder(temp);
}

int main()
{
    Node *root = NULL;
    // int a[] = {50, 76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
    // for(int i=0; i<16; i++){
    //     insert(&root, a[i]);
    // }
    // vector<int> c = {2, 3, 4, 14, 15, 21, 32, 50, 52, 64, 70, 76, 80, 83, 87, 100};
    // vector<int>d = {50, 21, 4, 2, 3, 15, 14, 32, 76, 64, 52, 70, 100, 83, 80, 87};
    vector<int> c = {-1};
    vector<int>d = {-1};
    //cout<<(max(&root))->data;
    //cout<<(search(&root, 0))->data;
    root = mp(c, d);
    print(&root);
    // cout<<del(&root, 5)<<endl;
    // print(&root);
    //levelorder(&root);
    return 0;
}


