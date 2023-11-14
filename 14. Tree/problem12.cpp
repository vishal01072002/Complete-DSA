// vertical traversal
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<utility>
#define MP map<int,map<int,vector<int>>>
#define P pair<int,int>
#define M map<int,vector<int>>
using namespace std;


// vertical traversal of binary Tree from left to right
// create maping of horizontal distance ,level and Node

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

vector<int> vertical2(node* root){
    vector<int> ans;
    if(root == NULL){ return ans;}

    MP mp;
    queue<pair<node*,P>> q;

    // initial values of HD = 0, level = 0
    q.push(make_pair(root,make_pair(0,0)));

    
    while(!q.empty()){
        pair<node*,P> temp = q.front();
        q.pop();

        // extract values
        node* frontVal = temp.first;
        int HDistance = temp.second.first;
        int level = temp.second.second;

        // make entry in map
        mp[HDistance][level].push_back(frontVal->data);

        // insert child
        if(frontVal->left){
            q.push(make_pair(frontVal->left, make_pair(HDistance-1, level+1)));
        }

        if(frontVal->right){
            q.push(make_pair(frontVal->right, make_pair(HDistance+1, level+1)));
        }
    }

    // store answer
    for(auto i: mp){
        for(auto j : i.second){
            for(auto k: j.second){
              ans.push_back(k);
            }
        }
    }
    return ans;
}


vector<int> vertical(node* root){
    vector<int> ans;
    if(root == NULL){ return ans;}

    M mp;
    queue<pair<node*,int>> q;

    // initial values of HD = 0, level = 0
    q.push(make_pair(root,0));

    
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        // extract values
        node* frontVal = temp.first;
        int HDistance = temp.second;

        // make entry in map
        mp[HDistance].push_back(frontVal->data);

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
        for(auto ele : i.second)
        ans.push_back(ele);
    }
    return ans;
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1   
    // ans 4 2 1 5 6 3 7

    vector<int> ans = vertical(root);
    cout << "\nTop View traversal of tree my ";
    for(auto i: ans){
        cout << i << " ";
    }

    vector<int> ans1 = vertical2(root);
    cout << "\nTop View traversal of tree ";
    for(auto i: ans1){
        cout << i << " ";
    }
    return 0;
}