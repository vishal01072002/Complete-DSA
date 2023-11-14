#include<iostream>
#include<queue>
using namespace std;

// find height / max depth of binary tree
// height ==> longest path between root and leafnode
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

// height = (currNode) 1 + max(left sub tree height, left sub tree height);
int height(node* root){
    if(root == NULL){
        return 0;
    }

    int LHeight = height(root->left);
    int RHeight = height(root->right);

    int ans = 1 + max(LHeight,RHeight);
    return ans;
}


int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    int ans = height(root);
    cout << "\nMax depth " << ans;
    return 0;
}