#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<utility>
#define P pair<node*,int>
#define M map<int,int>
using namespace std;


// right View of binary Tree from left to rigth

// when ever any node encounter at each level insert that 
// coz we need last element at each level

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



// *************** complete HW ******************
// using level order insert only first element at each new level from right


// <int, int>  ==>  level of curr node, value of node
vector<int> rightview2(node* root){
    vector<int> ans;
    if(root == NULL){ return ans;}

    M mp;
    queue<P> q;

    // node and that level
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        P temp = q.front();
        q.pop();

        node* frontVal = temp.first;
        int level = temp.second;

        // maintain one-to-one mapping
        // insert only first time
        if(mp.find(level) == mp.end()){
            mp[level] = frontVal->data;   
        }

        // insert child
        if(frontVal->right){
            q.push(make_pair(frontVal->right, level+1));
        }

        if(frontVal->left){
            q.push(make_pair(frontVal->left, level+1));
        }
    }

    // store answer
    for(auto i: mp){
        ans.push_back(i.second);
    }
    return ans;
}


// using recursion
// we have to store every first element when we go on new level
void rightView(node* root, vector<int> &ans, int level){
    if(root == NULL) return;

    // encounter new level
    if(ans.size() == level){
        ans.push_back(root->data);
    }

    rightView(root->right,ans,level+1);
    rightView(root->left,ans,level+1);

}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 4 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1   
    // ans 1 3 7 8

    vector<int> ans;
    rightView(root,ans,0);
    cout << "\nRight view traversal of tree ";
    for(auto i: ans){
        cout << i << " ";
    }

    vector<int> ans2 = rightview2(root);
    cout << "\nRight view 2 traversal of tree ";
    for(auto i: ans2){
        cout << i << " ";
    }
    return 0;
}