#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<utility>
#define P pair<node*,int>
#define M map<int,int>
using namespace std;


// bottom View of binary Tree from left to rigth

// create maping of horizontal distance and node
// when ever any node encounter at HDist insert that
// coz we have to go till bottom at every horizontal distance

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


// <int, int>  ==>  horizontal distance from root, value of node
vector<int> bottom(node* root){
    vector<int> ans;
    if(root == NULL){ return ans;}

    M mp;
    queue<P> q;

    // node and that horizontal diatance
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        P temp = q.front();
        q.pop();

        node* frontVal = temp.first;
        int HDistance = temp.second;

        // maintain one-to-one mapping
        mp[HDistance] = frontVal->data;    

        // insert child
        if(frontVal->left){
            q.push(make_pair(frontVal->left, HDistance-1));
        }

        if(frontVal->right){
            q.push(make_pair(frontVal->right, HDistance+1));
        }
    }

    // store answer
    for(auto i: mp){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1   
    // ans 4 2 6 3 7

    vector<int> ans = bottom(root);
    cout << "\nBottom view traversal of tree ";
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}