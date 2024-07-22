#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// check given binary tree is heap or not
// 1. check if this is complete binary tree
// 2. maintaining maxOrder or not
// i th node has left child at 2*i and right child at 2*i + 1

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

void heapify(vector<int> &arr, int n, int indx){
    int largest = indx;
    int left = 2*indx;
    int right = 2*indx + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != indx){
        swap(arr[largest],arr[indx]);
        heapify(arr,n,largest);
    }
}

bool isCBT(node* root, int index, int &nodes){
    if(root == NULL){
        return true;
    }

    if(index > nodes){
        return false;
    }
    else{
        bool left = isCBT(root->left, 2*index, nodes);
        bool right = isCBT(root->right, 2*index+1, nodes);

        return left && right;
    }
}

bool isMaxOrder(node* root){
    // if leaf
    if(!root->left && !root->right){
        return true;
    }
    
    // only left child
    if(!root->right){
        return (root->data > root->left->data);
    }

    else{
        left = isMaxOrder(root->left);
        right = isMaxOrder(root->right);

        return (left && right && 
                (root->data > root->left->data) &&
                (root->data > root->right->data)
               );
    }
}
int main(){
    
    vector<int> arr = {-1,1,4,7,8,4,2,5,9};
    int n = arr.size(); 
    //cout << n;
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;

    // make max heap
    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }

    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;

    if(isCBT() && isMaxOrder()){
        cout << "true";
    }

    return 0;
}