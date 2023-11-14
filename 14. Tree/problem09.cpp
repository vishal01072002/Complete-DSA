#include<iostream>
#include<queue>
#include<utility>
#define P pair<bool,int>
using namespace std;


// Sum Tree
// sum of all node in left sub tree AND right sub tree
// should be equal to parent of sub trees
// root = left + right
// should be true for each node (except leaf Node)

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



// complexity = O(N)
// <bool, int>  ==>  isSumTree , sum of all node of that sub tree
P isSumTree(node* root){
    if(root == NULL){
        P p = make_pair(true,0);
        return p;
    }

    // if leaf
    if(!root->left && !root->right){
        P p = make_pair(true,root->data);
        return p;
    }

    P leftpart = isSumTree(root->left);
    P rightpart = isSumTree(root->right);

    // calculate sum of both left and right sub trees
    int sum = leftpart.second + rightpart.second;
    // cout<<sum << " "<< leftpart.first<< " "<< rightpart.first << endl;

    P ans ;
    ans.second = sum + root->data;

    if(leftpart.first && rightpart.first && root->data == sum){
        ans.first = true;
        return ans;
    }

    ans.first = false;
    return ans;
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1   == > 0
    // 10 3 2 2 1 2 -1 -1 -1 -1 -1 -1 -1   == > 1

    P ans = isSumTree(root);
    cout << "\nIs tree is SumTree " << ans.first;
    return 0;
}