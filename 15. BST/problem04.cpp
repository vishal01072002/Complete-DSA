#include<iostream>
#include<queue>
using namespace std;

// delete node from Binary Search Tree
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

node* InPredecessor(node* root){
    if(root == NULL){
        return 0;
    }

    if(!root->left){
        return root;
    }
    root = root->left;
    while(root->right){
        root = root->right;
    }
    return root;
}

node* InSuccessor(node* root){
    if(root == NULL){
        return 0;
    }

    if(!root->right){
        return root;
    }

    root = root->right;
    while(root->left){
        root = root->left;
    }
    return root;
}

node* deleteBST(node* root, int target){
    if(root == NULL){
        return root;
    }

    if(root->data == target){
        // 0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        // 1 child in left
        if(root->left && !root->right){
            node* temp = root->left;
            delete root;
            return temp;
        }

        // 1 child in right
        if(root->right && !root->left){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left && root->right){
            // or max value from left subtree
            node* pred = InPredecessor(root);
            int value = pred->data;
            
            // change value of deleting node to predecessor
            root->data = value;
            
            // recursively delete that value
            root->left = deleteBST(root->left,value);
            return root;
        }
    }

    if(root->data > target){
        root->left = deleteBST(root->left,target);
    }
    else{
        root->right = deleteBST(root->right,target);
    }
    return root;
}

int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a BST ";
    inorder(root);

    int n = 5;
    root = deleteBST(root,n);
    cout << "\nInorder traversal of a BST after remove " << n << endl;
    inorder(root);

    
    return 0;
}