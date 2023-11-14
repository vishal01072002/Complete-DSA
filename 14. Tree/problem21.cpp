#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// find maximum sum of non adjecent nodes in Binary tree
// at every node we maintain sum with including and excluding
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


// use level order traversal 
// maintain sum of excluding and including for each node

pair<int,int> maxSum(node* root){
    pair<int,int> ans = make_pair(0,0);
    if(root == NULL){
        return ans;
    }

    pair<int,int> left = maxSum(root->left);
    pair<int,int> right = maxSum(root->right);

    // calculate current node inclusive sum
    int inclusive = root->data + left.second + right.second;

    // calculate current node exclusive sum
    int exclusive = max(left.first, left.second) + max(right.first, right.second);

    ans.first = inclusive;
    ans.second = exclusive;
    return ans;
}

int main(){
    node* root = NULL;

    levelOrderToTree(root);
    // 1 2 30 4 -1 5 6 -1 -1 -1 -1 -1 -1
    // ans 1 + 4 + 5 + 6 = 16

    pair<int,int> temp = maxSum(root);
    int ans = max(temp.first, temp.second);

    cout << "\nmaximum sum of non-adjecent nodes in tree " << ans ;
    return 0;
}