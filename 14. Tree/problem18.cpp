#include<iostream>
#include<queue>
#include<vector>
using namespace std;


// lowest common ancestor of Binary tree
// search for node exist 
// at particular point when node find that (left & right part) contain 
// that 2 nodes we return that node 

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


// using recursion
node* LCA(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        cout<<root->data;
        return root;
    }

    node* left = LCA(root->left, n1, n2); 
    node* right = LCA(root->right, n1, n2);

    if(left && right){
        return root;
    }
    if(left && !right){
        return left;
    } 
    else if(!left && right){
        return right;
    }
    else{
        return NULL;
    }
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 -1 -1 4 5 -1 -1 21 -1 -1 -1
    // search for 4,21
    // ans 3


    node* ans = LCA(root,4,21);
    cout << "\nlowest common ancestor of 4,21 in tree " << ans->data;
    return 0;
}