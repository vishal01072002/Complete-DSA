#include<iostream>
#include<queue>
using namespace std;


// morris traversal in a binary tree

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

void morris (node* root){
    if(root == NULL){
        return;
    }

    node* curr = root;

    // algo
    while(curr){
        if(! curr->left){
            cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            // find predecessor
            node* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }

            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;

            }
            else{
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }

}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    // ans 4 2 7 5 8 1 3 6 9 10

    
    cout << "\nmorris traversal of a binary tree ";
    morris(root);

    return 0;
}