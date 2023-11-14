#include<iostream>
#include<queue>
#include<vector>
using namespace std;


// find kth ancestor of node in Binary tree
// search for node exist 
// when found then start count in reverse from K to -1

// ====   NOTED  EDGE CASE  -- if ancester of searching node K is k(ansester)
// means no ancester found

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
node* KthLCA(node* root, int n, int &k){
    if(root == NULL){
        return NULL;
    }

    // element found return that node
    if(root->data == n){
        return root;
    }

    node* left = KthLCA(root->left, n, k); 
    node* right = KthLCA(root->right, n, k);

    if(left || right){
        k--;
        if(k == 0){
            // lock answer 
            k = INT_MAX;
            return root;
        }
        if(left){
            return left;
        }
        else{
            return right;
        }
    }
    else{
        return NULL;
    }
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 -1 -1 4 5 -1 -1 21 -1 -1 -1
    // search for 21's 2 ancester
    // ans 3

    int k = 2;
    node* ans = KthLCA(root,21,k);
    if(ans == NULL || ans->data == 21){
        cout<< "Not Found";
    }
    cout << "\nKth ancestor of 21 in tree " << ans->data;
    return 0;
}