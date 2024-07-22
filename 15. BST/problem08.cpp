#include<iostream>
#include<queue>
using namespace std;

// find lowest common ancester in Binary Search Tree 
// we use the propert of BST which is
// left subtree has small and right subtree has largest element

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

int LCA(node* root, int &n1, int &n2){
    if(root == NULL){
        return -1;
    }

    int curr = root->data;
    if(n1 < curr && n2 < curr){
        // means both exist in left part
        return LCA(root->left,n1,n2);
    }
    else if(n1 > curr && n2 > curr){
        // means both exist in right part
        return LCA(root->right,n1,n2);
    }
    else{
        // means one exist in left and other in right
        // this is first time divison
        // so this node is the LCA
        return root->data;
    }
}


int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);

    // for 2,9  ans = 5
    // for 1,4  ans = 2
    int n1 = 1;
    int n2 = 4;
    cout << "\nLCA of "<< n1 << " " << n2 <<" in BST is "<< LCA(root,n1,n2);
    return 0;
}