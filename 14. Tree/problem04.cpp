#include<iostream>
#include<queue>
using namespace std;

// count number of leaf node in binary tree
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

bool isleaf(node* root){
    if(root->left || root->right){
        return false;
    }
    return true;
}

void inorder(node* root, int &count){
    if(root == NULL){
        return;
    }

    inorder(root->left, count);
    if(isleaf(root)){
        count++;
    }

    inorder(root->right, count);
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    int count = 0;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    inorder(root, count);
    cout << "\nleaf node count " << count;
    return 0;
}