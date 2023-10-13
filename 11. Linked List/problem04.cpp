#include<iostream>
using namespace std;
#include<vector>

// reverse an Linked List

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

void reverseList(Node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }

    Node* temp ;
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
}

void recursive(Node* &head, Node* prev, Node* curr){
    if(curr == NULL){
        head = prev;
        return;
    }

    recursive(head,curr,curr->next);
    curr->next = prev;
}

Node* recursive2(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    // solve one case all will be solved by recursion
    Node* newHead = recursive2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    Node *head = NULL;

    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,3);
    InsertHead(head,4);
    InsertHead(head,5);

    print(head);

    reverseList(head);
    print(head);

    recursive(head,NULL,head);
    print(head);

    head = recursive2(head);
    print(head);

    return 0;
}