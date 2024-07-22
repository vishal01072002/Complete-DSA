#include<iostream>
#include<queue>
using namespace std;

// Binary Search Tree to Balanced BST
// balance BST - for each node difference of left and right sub tree
// must not be more than 1

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

// approach store inorder of BST in array and link them
node* balanceBST(vector<int> &in, int start, int end){
    if(start > end){
        return NULL;
    }

    // find mid to make root
    int mid = (start+end)/2;

    // make new node
    node* root = new node(in[mid]);

    // recursive call
    root->left = balanceBST(in,start,mid-1);
    root->right = balanceBST(in,mid+1,end);
    return root;
}

int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);

    vector<int> in;
    inorderVector(root,in);
    cout << "\nbalanced BST";
    root = balanceBST(in,0,in.size()-1);
    inorder(root);
    return 0;
}