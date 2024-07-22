#include<iostream>
#include<queue>
using namespace std;

// searching in a Binary Search Tree
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

// recursive
bool search(node* root, int val){
    if(root == NULL){
        return 0;
    }

    if(root->data == val){
        return 1;
    }

    if(val < root->data){
        return search(root->left,val);
    }
    else{
        return search(root->right,val);
    }
}

// Iterative
bool search2(node* root, int n){
    if(root == NULL){
        return 0;
    }

    while(root){
        if(root->data == n){
            return 1;
        }

        if(n < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return 0;
}

int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);
    // ans => 1 2 3 4 5 7 8 9

    int k = 9;
    cout << "\nsearching in BST for " << k << " " << search(root,k);
    cout << "\nsearching in BST for " << k << " " << search2(root,k);
    return 0;
}