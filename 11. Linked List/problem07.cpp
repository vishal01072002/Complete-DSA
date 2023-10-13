#include<iostream>
using namespace std;
#include<vector>

// detect Linked List is circular or not

class Node{
    public:
    int data;
    Node* next;

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

bool isCircular(Node* head){
    Node* temp = head;
    while(temp->next != head && temp != NULL){
        cout<<temp->data;
        temp = temp->next;
    }
    if(temp == NULL){
        return 0;
    }
    return 1;
}

int main(){
    Node *head = NULL;

    insertNode(head,1,0);
    insertNode(head,2,1);
    insertNode(head,5,2);
    insertNode(head,7,5);
    print(head);

    cout << isCircular(head);

    return 0;
}