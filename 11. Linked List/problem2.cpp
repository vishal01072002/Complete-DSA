#include<iostream>
using namespace std;

// implement dubbly linked list

class Node{
    public:
        
    int data;
    Node* next;
    Node* prev;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// insert at head
void InsertHead(Node* &head, Node* &tail, int d){
    Node *temp = new Node(d);
    if(head == NULL) {
        temp->next = head;
        tail = temp;
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp; 
    head = temp;
}

void insertTail(Node* &head, Node* &tail, int d){
    if(tail == NULL){
        InsertHead(head, tail ,d);
        return;
    }
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
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
    temp->next->prev = insertedNode;
    insertedNode->prev = temp;
    temp->next = insertedNode;

}

void deletePosition(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        if(head == NULL){
            // only one element
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
        return ;
    }

    Node* curr = head;
    Node* previous = NULL;
    int count = 1;

    while(count < pos){
        previous = curr;
        curr = curr->next;
        count++;
    }

    if(curr->next == NULL){
        // delete and update tail
        tail = previous;
    }

    previous->next = curr->next;
    curr->next->prev = previous;
    curr->next = NULL;
    curr->prev = NULL;
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