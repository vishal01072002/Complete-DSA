#include<iostream>
#include<queue>
using namespace std;

// Preorder array to Binary Search Tree
// approach 1 use create BST function O(N2)
// approach 2 find inorder and create tree from both in,pre function O(NLogN)
// approach 3 use preorder and INT_MAX & INT_MIN for track element function O(3N)

class node{
    public:

    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);  
}

node* insertBST(node* root, int value){
    if(root == NULL){
        node* temp = new node(value);
        return temp;
    }

    if(value > root-> data){
        root->right = insertBST(root->right, value);
    }
    else{
        root->left = insertBST(root->left, value);
    }
    return root;
}

void createBST(node* &root){
    cout << "enter values to insert in BST -1 for end ";
    int value;
    cin >> value;

    while(value != -1){
        root = insertBST(root, value);
        cin >> value;
    }
}

void inorderVector(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }

    inorderVector(root->left,in);
    in.push_back(root->data);
    inorderVector(root->right,in);
}

node* preToBST(vector<int> &pre, int mini, int maxi, int &indx){
    if(indx >= pre.size()){
        return NULL;
    }

    int value = pre[indx];

    // not lie in range
    if(value < mini || value > maxi){
        return NULL;
    }

    // lie in range make new root

    node* root = new node(pre[indx++]);

    // recursive call
    root->left = preToBST(pre,mini,value,indx);
    root->right = preToBST(pre,value,maxi,indx);
    return root;
}

int main(){
    node* root = NULL;
    vector<int> in;
    int indx = 0;
    vector<int> pre = {20,10,5,15,13,35,30,42};
    inorderVector(root,in);
    cout << "\nInorder traversal of preorder to BST ";
    root = preToBST(pre,INT_MIN,INT_MAX,indx);
    inorder(root);
    return 0;
}