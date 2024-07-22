#include<iostream>
#include<queue>
using namespace std;

// Merge 2 Binary Search Tree
// approach 1 
// find inorder of both BST
// apply merge two sorted array
// make tree tree from inorder like problem12.cpp 
// Time Complexity O(N+M)
// space Complexity O(N+M)

// approach 2 
// convert BST in to Sorted doubly linked list ==> T.C = O(N) S.C = O(h)
// apply merge two sorted LL ====> T.C = O(N) S.C = O(1) 
// make BST from sorted linked list (approach same as problem12.cpp) 
// ==> T.C = O(LogN) S.C = O(h)
// total
// Time Complexity O(N+M)
// space Complexity O(H(N) + H(M))

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

void traverse(node* head){
    while(head){
        cout<<head->data<< " ";
        head = head->right;
    }
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);  
}

node* insertBST(node* root, int value){
    if(root == NULL){
        node* temp = new node(value);
        return temp;
    }

    if(value > root-> data){
        root->right = insertBST(root->right, value);
    }
    else{
        root->left = insertBST(root->left, value);
    }
    return root;
}

void createBST(node* &root){
    cout << "enter values to insert in BST -1 for end ";
    int value;
    cin >> value;

    while(value != -1){
        root = insertBST(root, value);
        cin >> value;
    }
}

int lengthLL(node* head){
    int ans = 0;
    while(head){
        ans++;
        head = head->right;
    }
    return ans;
}

node* BstToDLL(node* root, node* &head){
    if(root == NULL){
        return NULL;
    }
    BstToDLL(root->right, head);

    root->right = head;
    if(head){
        head->left = root;
    }

    head = root;

    BstToDLL(root->left,head);
    return head;
}

node* mergeLL(node* root1, node* root2){
    if(!root1) return root2;
    if(!root2) return root1;

    node* head = NULL;
    node* tail = NULL;

    while(root1 && root2){
        if(root1->data < root2->data){
            if(!head){
                head = root1;
                tail = root1;
            }
            // insert at tail in doubly LL
            else{
                tail->right = root1;
                tail = tail->right;
                root1->left = NULL;
            }
                root1 = root1->right;
        }
        else{
            if(!head){
                head = root2;
                tail = root2;
            }
            // insert at tail in doubly LL
            else{
                tail->right = root2;
                tail = tail->right;
                root2->left = NULL;
            }
                root2 = root2->right;
        }
    }

    while(root1){
        cout<<"hi ";
        tail->right = root1;
        root1->left = NULL;
        tail = tail->right;
        root1 = root1->right;
    }

    while(root2){
        tail->right = root2;
        root2->left = NULL;
        tail = tail->right;
        root2 = root2->right;
    }

    return head;
}


node* LLToBST(node* &head, int len){
    if(len <= 0 || head == NULL){
        return NULL;
    }

    node* left = LLToBST(head,len/2);
    node* root = head;
    head->left = left;
    head = head->right;

    root->right = LLToBST(head,len - (len/2) - 1);
    return root;

}


int main(){
    node* root1 = NULL;
    node* root2 = NULL;
    createBST(root1);
    createBST(root2);
    cout << "\nInorder traversal of a binary search tree ";
    // 5 2 7 1 4 9 3 8 -1
    inorder(root1);

    cout << "\ntraversal of double 1st LL ";
    node* head1 = NULL;
    node* temp = BstToDLL(root1,head1);
    traverse(head1);
    cout << "\ntraversal of double 2st LL ";
    node* head2 = NULL;
    temp = BstToDLL(root2,head2);
    traverse(head2);

    // merge
    node* head = mergeLL(head1,head2);
    cout << "\ntraversal of double merge LL ";
    traverse(head);

    cout << "\ntraversal of merge bst tree ";
    int lens = lengthLL(head);
    root1 = LLToBST(head,lens);
    inorder(root1);
    return 0;
}