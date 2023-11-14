#include<iostream>
#include<queue>
using namespace std;

// creating binary tree and level order traversal
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

node* createTree(node* &root){
    
    cout << "enter node data or -1 for NO ";
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout << "for left child of " << root->data << " ";
    root->left = createTree(root->left);

    cout << "for right child of " << root->data << " ";
    root->right = createTree(root->right);

    return root;
}
void levelOrder(node* root){
    cout<<"Printing levelorder \n";
    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // means that level is comleted
            cout << endl;
            // and that level all child will also added in queue
            if(!q.empty()){
                q.push(NULL);
            } 
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                //cout<<temp->left->data;
                q.push(temp->left);
            }

            if(temp->right){
                //cout<<temp->right->data;
                q.push(temp->right);
            }
        }
    }   
}

int main(){
    node* root = NULL;

    root = createTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrder(root);
    return 0;
}