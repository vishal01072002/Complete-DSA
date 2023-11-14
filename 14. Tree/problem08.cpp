#include<iostream>
#include<queue>
#include<utility>
using namespace std;

// check for two binary tree are identical or not
// balance tree ==> abs(LHeight - RHeight) <= 1
// for each node

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

bool isIdentical(node* r1, node* r2){
    if(!r1 && !r2) return 1;
    if(r1 && !r2) return 0;
    if(!r1 && r2) return 0;

    if(r1->data == r2->data){
        bool left = isIdentical(r1->left , r2->left);
        bool right = isIdentical(r1->right , r2->right);
        if(left && right) return 1;
    }
    return 0;
}

bool isIdentical2(node* r1, node* r2){
    if(!r1 && !r2) return 1;
    if(r1 && !r2) return 0;
    if(!r1 && r2) return 0;

    bool left = isIdentical(r1->left , r2->left);
    bool right = isIdentical(r1->right , r2->right);

    if(r1->data == r2->data && left && right){
        return 1;
    }
    return 0;
}

int main(){
    node* root1 = NULL;
    node* root2 = NULL;

    levelOrderToTree(root1);
    levelOrderToTree(root2);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // 1 3 6 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // bool ans = isbalance(root);
    // cout << "\nTree is balance " << ans;
    
    bool ans1 = isIdentical(root1,root2);
    bool ans2 = isIdentical2(root1,root2);
    cout << "\nTrees are identical " << ans1;
    cout << "\nTrees are identical " << ans2;
    return 0;
}