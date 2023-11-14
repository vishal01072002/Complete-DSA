#include<iostream>
#include<map>
#include<vector>
using namespace std;


// build a binary tree from inorder/preorder traversal
// preorder NLR
// postorder LRN
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

void inOrder(node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);  
}

void createMaping(vector<int> &inorder, map<int,int> &mp){
    for(int i=0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
    }
}

node* buildtree(vector<int> &inorder, vector<int> &preorder, int &preIndx,int inIndx,int inEnd,int n, map<int,int> &mp){

    // base case
    if(preIndx >= n || inIndx > inEnd){
        return NULL;
    }

    // find root element from preorder which is on 1st index
    int element = preorder[preIndx];
    
    // make node of that element
    node *root = new node(element);

    // find position in inorder
    int position = mp[element];

    // update preorder index by one
    preIndx++;

    // recursive call
    root->left = buildtree(inorder,preorder,preIndx,inIndx,position-1,n,mp);
    root->right = buildtree(inorder,preorder,preIndx,position+1,inEnd,n,mp);

    return root;
}

int main(){
    int n = 6;
    vector<int> inorder = {3,1,4,0,5,2};
    vector<int> preorder = {0,1,3,4,2,5};

    // pre index should we traverse only one so pass it by reference
    int preIndx = 0;
    int inIndx = 0;
    int inEnd = n-1;

    // create maping for searching in O(1);
    map<int,int> mp;
    createMaping(inorder,mp);

    node* root = buildtree(inorder,preorder,preIndx,inIndx,inEnd,n,mp);
    cout << "\ntree in order traversal is ";
    inOrder(root) ;
    return 0;
}