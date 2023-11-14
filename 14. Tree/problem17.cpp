#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<utility>
#define P pair<node*,int>
#define M map<int,int>
using namespace std;


// sum of longest bloodline of a tree
// OR sum of node on longest path from root to leaf

// when we hit leaf check if path is long than prev update len and sum

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
void bloodLine(node* root, int sum, int &ans, int len, int &maxLen){
    if(root == NULL){
        // we are in end
        if(len > maxLen){
            maxLen = len;
            ans = sum;
        }
        else if(len == maxLen){
            // length same may be sum is also greater
            ans = max(ans,sum);
        }
        return;
    }

    sum = sum + root->data;
    bloodLine(root->left,sum,ans,len+1,maxLen);
    bloodLine(root->right,sum,ans,len+1,maxLen);
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 
    // ans 4 + 2 + 1 + 6  = 13

    int sum = 0;
    int ans = 0; // --------- check
    int len = 1; // for root
    int maxLen = 0;
    bloodLine(root,sum,ans,len,maxLen);
    cout << "\nsum of longest path of tree " << ans;
    return 0;
}