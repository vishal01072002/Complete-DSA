#include<iostream>
using namespace std;

// implement Circular linked list

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

void insertNode(Node* &head, int value, int element){
    Node* temp = new Node(value);
    if(head == NULL){
        temp->next = temp;
        head = temp;
        return ;
    }

    Node* current = head;
    while(current->data != element){
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
}

void deleteNode(Node* &head, int value){
    if(head == NULL){
        cout<<"empty"<<endl;
        return;
    }
    if(head->data == value){
        Node* temp = head;
        if(head->next = head){
            head = NULL;
        }
        else{
            head = head->next;
            delete temp;
        }
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next == NULL;
    cout<<curr->data<<prev->next->data<<endl;
    delete curr;

}

void print(Node *head){
    if(head == NULL){
        cout<<"print null"<<endl;
        return;
    }
    Node* temp = head;
    do{
        cout<<temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;   
}

int main()
{
    Node* head = NULL;

    insertNode(head,1,0);
    print(head);

    deleteNode(head,1);
    print(head);

    insertNode(head,2,1);
    print(head);

    insertNode(head,5,2);
    print(head);

    insertNode(head,7,5);
    print(head);

    deleteNode(head,7);
    print(head);
    return 0;
}
