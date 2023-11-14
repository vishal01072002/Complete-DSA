#include<iostream>
#include<queue>
#include<utility>
using namespace std;

// find diameter of binary tree
// diameter ==> longest path between 2 nodes
// and number of nodes in that path known as diameter
// these 2 node can be root node / leaf node

// approach
// diameter can exist in 3 way
// 1. diameter exist in only left subtree
// 2. diameter exist in only right subtree
// 3. diameter exist in both subtree and include root

// ans = max(Left dia, Right dia, (LHeight + RHeight + 1))
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
int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int LDia = diameter(root->left);
    int RDia = diameter(root->right);

    int LHeight = height(root->left);
    int RHeight = height(root->right);

    int currDia = LHeight + RHeight + 1;

    return max(currDia, max(LDia,RDia));
}

// complexity = O(N)
// <int, int>  ==>  diameter , height
pair<int,int> fastDiameter(node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }


    pair<int,int> LeftPart = fastDiameter(root->left);
    pair<int,int> RightPart = fastDiameter(root->right);

    int LDia = LeftPart.first;
    int RDia = RightPart.first;

    int LHeight = LeftPart.second;
    int RHeight = RightPart.second;

    int height = 1 + max(LHeight,RHeight);

    // current tree full diameter
    int currDia = LHeight + RHeight + 1;
    int ansDia = max(currDia, max(LDia, RDia));
    
    pair<int,int> ans;
    ans.first = ansDia;
    ans.second = height;
    return ans;
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // int ans = diameter(root);
    // cout << "\nDiameter of tree is " << ans;
    
    pair<int,int> ans = fastDiameter(root);
    cout << "\nDiameter of tree is " << ans.first;
    return 0;
}