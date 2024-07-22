#include<iostream>
#include<queue>
using namespace std;

// find largest BST in Binary Tree
// approach 1 
// check for BST for each node 
// Time Complexity O(N2)
// space Complexity O(H)

// approach 2 
// store some information for each node like
// mini, maxi, BST Size, is BST
// Time Complexity O(N)
// space Complexity O(H)

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

class info{
    public:
    
    int maxi;
    int mini;
    bool isBST;
    int size;
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

info largeBST(node* root, int &maxSize){
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = largeBST(root->left,maxSize);
    info right = largeBST(root->right,maxSize);

    info current;
    current.size = left.size + right.size + 1;
    current.maxi = max(root->data,right.maxi);
    current.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && root->data >= left.maxi && root->data <= right.mini){
        current.isBST = true;
    }
    else{
        current.isBST = false;
    }

    if(current.isBST){
        maxSize = max(maxSize, current.size);
    }
    return current;
}

int main(){
    node* root = NULL;
    createBST(root);
    cout << "\nInorder traversal of a binary search tree ";
    // 5 2 7 1 4 9 3 8 -1
    inorder(root);

    cout << "\nLargest BST size in Binary tree is  ";
    int maxsize = INT_MIN;
    info ans = largeBST(root,maxsize);
    cout<< maxsize;
    return 0;
}