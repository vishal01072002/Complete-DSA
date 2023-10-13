#include<iostream>
using namespace std;
#include<vector>

// check given Linked List is palandrome or not.

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void InsertHead(Node* &head, int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// approach 1 using vector to store data of linked list
bool isPalandrome(Node* head){
    vector<int> ans;
    while(head){
        ans.push_back(head->data);
        head = head->next;
    }

    int s = 0;
    int e = ans.size() - 1;
    while(s<=e){
        if(ans[s++] != ans[e--]) return 0;
    }
    return 1;
}

// approach 2 With out extra space
// first reverse the half linked list
// apply slow and fast pointer approach to check palandrome
Node* reverseList(Node* &head){
    if(!head || !head->next) return head;
    

    Node* reverseHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return reverseHead;
}

bool isPalandrome2(Node* &head){
    // only one element or no element
    if(!head || !head->next) return 1;
    Node* mid = NULL;
    Node* slow = head;
    Node* fast = head->next;

    // first find mid
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow->next;

    // reverse second half
    Node * reverseHead = reverseList(mid);

    // now check palandrme
    while(reverseHead){
        if(head->data != reverseHead->data){
            return 0;
        }
        head = head->next;
        reverseHead = reverseHead->next;
    }
    return 1;
}

int main(){
    Node *head = NULL;
    Node *head1 = NULL;

   
    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,1);

    print(head);
    cout<< "first alog " << isPalandrome(head) << endl;
    print(head);
    cout<< "second algo " << isPalandrome2(head);


    return 0;
}