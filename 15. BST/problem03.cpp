#include<iostream>
#include<queue>
using namespace std;

// minimum value, maximum value in a Binary Search Tree
// inorder predecessor/ Inorder sucessor in BST

// Inorder Predecessor of Node => maximum value in left subtree 
// Inorder sucessor of Node => minimum value in right subtree 
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

// Iterative
int minBST(node* root){
    if(root == NULL){
        return -1;
    }

    while(root->left){
        root = root->left;
    }
    return root->data;
}

int maxBST(node* root){
    if(root == NULL){
        return -1;
    }

    while(root->right){
        root = root->right;
    }
    return root->data;
}

node* InPredecessor(node* root, int n){
    if(root == NULL){
        return -1;
    }

    int ans = -1;
    // first search for that
    while(root){
        if(root->data == n){
            break;
        }
        else if(root->data > n){
            root = root->left;
        }
        else{
            ans = root->data;
            root = root->right;
        }
    }

    if(root){
        root = root->left;
    }

    while(root->right){
        root = root->right;
    }
    return root;
}

node* InSuccessor(node* root, int n){
    if(root == NULL){
        return -1;
    }

    int ans = -1;
    // first search for that
    while(root){
        if(root->data == n){
            break;
        }
        else if(root->data > n){
            ans = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    if(root){
        root = root->right;
    }

    while(root->left){
        root = root->left;
    }
    return root;
}

int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);

    cout << "\nminimum in BST "<< minBST(root);
    cout << "\nmaximum in BST "<< maxBST(root);

    cout << "\nInorder predecessor in BST "<< InPredecessor(root,7)->data;
    cout << "\nInorder successor in BST "<< InSuccessor(root,7)->data;


    return 0;
}