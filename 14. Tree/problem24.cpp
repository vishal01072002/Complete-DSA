#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<utility>
#define P pair<int,int>
#define M map<node*,bool>
using namespace std;


// minimum time to burn a binary tree
// only adjecent node will burn in every 1 sec
// create maping of burned node  -- is burn or not

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

// child to parent mapping
void createMaping(node* root, map<node*,node*> &parent, int n, node* &ans){
    if(root == NULL){
        return;
    }

    // finding burning node
    int value = root->data;
    if(value == n){
        ans = root;
    }

    if(root->left){
        parent[root->left] = root;
        createMaping(root->left,parent,n,ans);
    }
    if(root->right){
        parent[root->right] = root;
        createMaping(root->right,parent,n,ans);
    }
}

void burntree(int &time, node* burnLeaf, map<node*,node*> parent){
    
    M visited;
    queue<node*> q;
    // initial value
    q.push(burnLeaf);
    visited[burnLeaf] = 1;

    while(!q.empty()){
        // to track change at any time any leaf is burn or not
        int flag = 0;
        int size = q.size();

        for(int i=0; i<size; i++){
            // process adjecent node of temp
            node* temp = q.front();
            q.pop();

            // left
            if(temp->left && !visited[temp->left]){
                flag = 1;
                visited[temp] = 1;
                q.push(temp->left);
            }
            
            // right
            if(temp->right && !visited[temp->right]){
                flag = 1;
                visited[temp] = 1;
                q.push(temp->right);
            }

            // parent
            if(parent[temp] && !visited[parent[temp]]){
                flag = 1;
                visited[parent[temp]] = 1;
                q.push(parent[temp]);
            }
        }

        if(flag == 1){
            // new leaf burns
            time++;
        }
    }
    return;
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    // ans 7 for n = 8
    // ans 5 for n = 6

    int n = 6;
    int ans = 0;
    map<node*,node*> parent;
    node* givenNode = NULL;
    createMaping(root,parent,n,givenNode);

    // map parent of root to NULL
    parent[root] = NULL;
    burntree(ans,givenNode,parent);
    cout << "\nTime to burn a binary tree from node " << n << " " << ans;

    return 0;
}