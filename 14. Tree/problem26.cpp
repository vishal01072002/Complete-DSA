#include<iostream>
#include<queue>
using namespace std;

// morris traversal application flatten a binary tree in linked list

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

void print(node* root){
    while(root){
        cout << root->data << " ";
        root = root->right;
    }
}

void morrisFlatten (node* root){
    if(root == NULL) return;
    node* curr = root;

    // algo
    while(curr){
        if(curr->left){
            // find predecessor
            node* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }

            // link pred to curr->right & right to left
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    // ans 1 2 4 5 7 8 3 6 9 10

    
    morrisFlatten(root);
    cout << "\nmorris Flatten of a binary tree ";
    print(root);

    return 0;
}