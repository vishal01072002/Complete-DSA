#include<iostream>
#include<queue>
using namespace std;

// creating binary tree and from level order traversal
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

        cout << "enter data for left child of " << temp->data << " ";
        cin >> data;
        if(data != -1){
            temp->left = new node(data);
            q.push(temp->left);
        }
        
        cout << "enter data for right child of " << temp->data << " ";
        cin >> data;
        if(data != -1){
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
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

    levelOrderToTree(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrder(root);
    return 0;
}