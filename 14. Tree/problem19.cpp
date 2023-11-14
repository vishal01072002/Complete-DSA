#include<iostream>
#include<queue>
#include<vector>
using namespace std;


// K Sum path in Binary tree
// search number of paths that have sum equal to K 
// try all possible path 

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
void SumPath(node* root, int k, int &count, vector<int> path){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);

    // recursive call
    SumPath(root->left, k, count, path);
    SumPath(root->right, k, count, path);

    // check for answer
    int size = path.size();
    int sum = 0;
    for(int i=size-1; i>=0; i--){
        sum += path[i];
        if(sum == k){
            count++;
            break;
        }
    }
    
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 -1 -1 4 6 -1 -1 -2 -1 -1 -1
    // search for k = 4
    // ans number of path = 3

    int ans = 0;
    int k = 4;
    vector<int> path;
    SumPath(root, k, ans, path);
    cout << "\nK Sum of tree " << ans;
    return 0;
}