#include<iostream>
using namespace std;
#include<vector>
#include<map>

// Remove duplicates from sorted Linked List.
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

// by change pointer
void removeDuplicate(Node* head){
    if(!head){
        return ;
    }
    while(head != NULL && head->next != NULL){
        if(head->data == head->next->data){
            head->next = head->next->next;
        }
        else{
            head = head->next;
        }
    }
    return ;
}

// by change values of node
void removeDuplicate2(Node* head){
    if(!head){
        return ;
    }

    Node* temp = head;

    while(temp!= NULL && temp->next != NULL){
        if(temp->data == temp->next->data){
            temp = temp->next;
        }
        else{
            head = head->next;
            temp = temp->next;
            head->data = temp->data;
        }
    }
    head->next = NULL;
    return ;
}


int main(){
    Node *head = NULL;

    InsertHead(head,7);
    InsertHead(head,6);
    InsertHead(head,5);
    InsertHead(head,5);
    InsertHead(head,4);
    InsertHead(head,3);
    InsertHead(head,2);
    InsertHead(head,2);
    InsertHead(head,1);
    InsertHead(head,1);
    print(head);

    removeDuplicate(head);
    // removeDuplicate2(head);
    print(head);

    return 0;
}