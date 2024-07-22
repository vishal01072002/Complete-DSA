#include<iostream>
#include<queue>
using namespace std;

// find Kth largest element in Binary Search Tree 
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

    inorder(root->right);  
    cout << root->data << " ";
    inorder(root->left);
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

// inorder is in asscending LNR 
// when we on N instead print we increase count
// when k == count that is answer

int Kthlarge(node* root, int &count, int &k){
    if(root == NULL){
        return -1;
    }

    // L
    int right = Kthlarge(root->right,count,k);
    if(right != -1){
        return right;
    }    

    // N
    count++;
    if(count == k){
        return root->data;
    }

    // R
    int left = Kthlarge(root->left, count, k);
    // it can be answer or -1
    return left;
}


int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);

    int count = 0;
    int k = 3;
    cout << "\n" << k << "th largest number in BST is "<< Kthlarge(root,count,k);
    return 0;
}