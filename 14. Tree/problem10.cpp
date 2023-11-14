#include<iostream>
#include<queue>
#include<utility>
using namespace std;

// Zig Zag traversal in tree
// first left to right then right to left
// use Level Order Traversal

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

vector<int> zigzag(node* root){
    vector<int> ans;
    if(root == NULL){ return ans;}

    queue<node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> tempArr(size);

        for(int i=0; i<size; i++){

            node* temp = q.front();
            q.pop();

            // save according to right or left
            int index = (leftToRight) ? i : size - i-1;
            tempArr[index] = temp->data;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);   
        }
        leftToRight = !leftToRight;
        for(auto val: tempArr){
            ans.push_back(val);
        }    
    }
    return ans;
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    // ans = 1 5 3 7 11 17

    vector<int> ans = zigzag(root);
    cout << "\nZig Zag traversal of tree ";
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}