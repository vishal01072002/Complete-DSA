#include<iostream>
#include<queue>
using namespace std;

// Creating an Binary Search Tree
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

int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    // ans => 1 2 3 4 5 7 8 9
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);
    return 0;
}