#include<iostream>
#include<map>
#include<vector>
using namespace std;


// build a binary tree from inorder/postorder traversal
// preorder NLR  ===> index 0 to n
// postorder LRN  ===> index n to 0

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

node* buildtree(vector<int> &inorder, vector<int> &postorder, int &postIndx,int inIndx,int inEnd,int n, map<int,int> &mp){

    // base case
    if(postIndx < 0 || inIndx > inEnd){
        return NULL;
    }

    // find root element from postorder which is on 1st index
    int element = postorder[postIndx];
    
    // make node of that element
    node *root = new node(element);

    // find position in inorder
    int position = mp[element];

    // update postorder index by one
    postIndx--;

    // recursive call first for right coz LRN we are going in reverse order
    root->right = buildtree(inorder,postorder,postIndx,position+1,inEnd,n,mp);
    root->left = buildtree(inorder,postorder,postIndx,inIndx,position-1,n,mp);

    return root;
}

int main(){
    int n = 8;
    vector<int> inorder = {4,8,2,5,1,6,3,7};
    vector<int> postorder = {8,4,5,2,6,7,3,1};

    // pre index should we traverse only one so pass it by reference
    int postIndx = n-1;
    int inIndx = 0;
    int inEnd = n-1;

    // create maping for searching in O(1);
    map<int,int> mp;
    createMaping(inorder,mp);

    node* root = buildtree(inorder,postorder,postIndx,inIndx,inEnd,n,mp);
    cout << "\ntree in order traversal is ";
    inOrder(root) ;
    return 0;
}