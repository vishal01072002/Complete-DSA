#include<iostream>
#include<queue>
using namespace std;

// check given tree is Binary Search Tree or NOT
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


bool isBST(node* root, int min, int max){
    if(root == NULL){
        return 1;
    }

    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);

        return left && right;
    }

    return 0;
}

int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);

    cout << "\nIs given tree is BST "<< isBST(root,INT_MIN,INT_MAX);
    return 0;
}