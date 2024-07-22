#include<iostream>
#include<queue>
using namespace std;

// Two Sum in Binary Search Tree
// find two number which sum equal to target

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


void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);  
}


node* insertBST(node* root, int value){
    if(root == NULL){
        node* temp = new node(value);
        return temp;
    }

    if(value > root-> data){
        root->right = insertBST(root->right, value);
    }
    else{
        root->left = insertBST(root->left, value);
    }
    return root;
}

void createBST(node* &root){
    cout << "enter values to insert in BST -1 for end ";
    int value;
    cin >> value;

    while(value != -1){
        root = insertBST(root, value);
        cin >> value;
    }
}

void inorderVector(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }

    inorderVector(root->left,in);
    in.push_back(root->data);
    inorderVector(root->right,in);  
}

// approach store inorder of BST in array and then apply 2 pointer approach
bool twoSum1(int target, vector<int> &in){
    int i= 0;
    int j= in.size()-1;

    while(i<j){
        if(in[i] + in[j] == target){
            return true;
        }
        if(in[i] + in[j] < target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

int main(){
    node* root = NULL;
    createBST(root);

    // 5 2 7 1 4 9 3 8 -1
    cout << "\nInorder traversal of a binary search tree ";
    inorder(root);

    vector<int> in;
    int target = 100;
    inorderVector(root,in);
    cout << "\nis two sum for target "<< target << " " << twoSum1(target,in);
    return 0;
}