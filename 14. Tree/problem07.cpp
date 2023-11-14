#include<iostream>
#include<queue>
#include<utility>
using namespace std;

// check for balance binary tree
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

// complexity = O(N2)
bool isbalance(node* root){
    if(root == NULL){
        return 1;
    }

    bool left = isbalance(root->left);
    bool right = isbalance(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left &&  right && diff){
        return 1;
    }
    return 0;

}

// complexity = O(N)
// <bool, int>  ==>  isbalance , height of that sub tree
pair<bool,int> isbalanceFast(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(1,0);
        return p;
    }

    pair<bool,int> leftpart = isbalanceFast(root->left);
    pair<bool,int> rightpart = isbalanceFast(root->right);

    // height to send in next call
    int height = max(leftpart.second, rightpart.second) + 1;

    // difference of height fo is balance
    bool diff = abs(leftpart.second - rightpart.second) <= 1;

    pair<bool,int> ans;
    ans.second = height;
    if(diff && leftpart.first && rightpart.first){
        ans.first = 1;
        return ans;
    }

    ans.first = 0;
    return ans;
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // bool ans = isbalance(root);
    // cout << "\nTree is balance " << ans;
    
    pair<bool,int> ans = isbalanceFast(root);
    cout << "\nTree is balance " << ans.first;
    return 0;
}