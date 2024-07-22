#include<iostream>
#include<queue>
using namespace std;

// Flatten a Binary Search Tree in sorted order

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

void traverse(node* root){
    if(root == NULL){
        return;
    }

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

void inorderVector(node* root, vector<node*> &in){
    if(root == NULL){
        return;
    }

    inorderVector(root->left,in);
    in.push_back(root);
    inorderVector(root->right,in);  
}

// approach store inorder of BST in array and link them
node* flatten(vector<node*> &in){
    int i= 0;
    int j= in.size();

    for(i; i<j-1; i++){
        in[i]->right = in[i+1];
        in[i]->left = NULL;
    }

    in[j-1]->left = NULL;
    in[j-1]->right = NULL;
    return in[0];
}

int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);

    vector<node*> in;
    inorderVector(root,in);
    cout << "\nFlatten BST is ";
    root = flatten(in);
    traverse(root);
    return 0;
}