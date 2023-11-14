#include<iostream>
#include<queue>
#include<utility>
using namespace std;

// boundry traversal in tree

// can be break in 3 parts
// 1. left part (with out leaf)
// 2. leaf part
// 3. right part (with out leaf) in reverse order

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

void levelOrderToTree(node* &root){
    queue<node*> q;
    cout << "enter root node data ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        // cout << "enter data for left child of " << temp->data << " ";
        cin >> data;
        if(data != -1){
            temp->left = new node(data);
            q.push(temp->left);
        }
        
        // cout << "enter data for right child of " << temp->data << " ";
        cin >> data;
        if(data != -1){
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}

void leftBoundry(node* root){
    if(root == NULL || !root->left && !root->right) return;

    cout << root->data << " ";

    // edge case if left not exist
    if(root->left){
        leftBoundry(root->left);
    }
    else{
        leftBoundry(root->right);
    }

}

void leafBoundry(node* root){
    if(root == NULL) return;

    // if leaf
    if(!root->left && !root->right){
        cout << root->data << " ";
    }

    leafBoundry(root->left);
    leafBoundry(root->right);
}

void rightBoundry(node* root){
    if(root == NULL || !root->left && !root->right) return;

    if(root->right){
        rightBoundry(root->right);
    }
    else{
        rightBoundry(root->left);
    }

    // printing in reverse order
    cout << root->data << " ";
}

void boundryTraverse(node* root){
    if(root == NULL) return; 

    cout << root->data << " ";
    leftBoundry(root->left);
    leafBoundry(root);
    rightBoundry(root->right);
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 10 11 -1 -1 -1 -1
    // ans = 1 2 3 4 7 8 10 11 9 6 3

    cout << "\nBoundry of traversal of tree ";
    boundryTraverse(root);
    return 0;
}