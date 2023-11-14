#include<iostream>
#include<queue>
using namespace std;

// inorder, preorder, postorder traversal
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

node* createTree(node* &root){
    
    cout << "enter node data or -1 for NO ";
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout << "for left child of " << root->data << " ";
    root->left = createTree(root->left);

    cout << "for right child of " << root->data << " ";
    root->right = createTree(root->right);

    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);  
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);  
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);  
    cout << root->data << " ";
}

int main(){
    node* root = NULL;

    root = createTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    inorder(root);
    cout << endl;
    
    preorder(root);
    cout << endl;
    
    postorder(root);
    return 0;
}