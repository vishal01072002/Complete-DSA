#include<iostream>
using namespace std;
#include<vector>

// Middle element of an Linked List

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

Node* middleList(Node* &head){
    if(head->next == NULL){
        return head
    }

    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){
    Node *head = NULL;

    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,3);
    InsertHead(head,4);
    InsertHead(head,5);

    print(head);

    Node* temp = middleList(head);
    cout<<temp->data;

    return 0;
}