#include<iostream>
using namespace std;

// implement singly linked list

class Node{
    public:
        
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// insert at head
void InsertHead(Node* &head,Node* &tail, int d){
    Node *temp = new Node(d);
    temp->next = head;
    if(head == NULL) tail = temp;
    head = temp;
}

void insertTail(Node* &head, Node* &tail, int d){
    if(tail == NULL){
        InsertHead(head, tail ,d);
        return;
    }
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
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

void insertPosition(Node* &head, Node* &tail, int pos, int d){
    if(pos == 1){
        InsertHead(head,tail,d);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count< pos-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertTail(head, tail, d);
        return ;
    }

    Node* insertedNode = new Node(d);
    insertedNode->next = temp->next;
    temp->next = insertedNode;

}

void deletePosition(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        if(head == NULL){
            // only one element
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
        return ;
    }

    Node* curr = head;
    Node* prev = NULL;
    int count = 1;

    while(count < pos){
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(curr->next == NULL){
        // delete and update tail
        tail = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    /*
    print(head);
    InsertHead(head, tail, 1);
    print(head);
    InsertHead(head, tail, 2);
    print(head);
    InsertHead(head, tail, 3);
    print(head);
    InsertHead(head, tail, 4);
    print(head);
    */

    /*
    print(head);
    insertTail(head, tail, 1);
    print(head);
    insertTail(head, tail, 2);
    print(head);
    insertTail(head, tail, 3);
    print(head);
    insertTail(head, tail, 4);
    print(head);
    */

   insertTail(head,tail,23);
   insertTail(head,tail,3);
   insertTail(head,tail,1);
   print(head);
   deletePosition(head,tail,2);
   print(head);
   deletePosition(head,tail,2);
   print(head);
   deletePosition(head,tail,1);
   print(head);

    return 0;
}