#include<iostream>
using namespace std;
#include<algorithm>

// Add 2 number represented by Linked List.

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

Node* reverse(Node* &head){
    if(! head || !head->next) return head;

    Node* curr = head;
    Node* prev = NULL;
    Node* nexts = head;
    while(curr){
        nexts = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nexts;
    }
    return prev;
}

void insertTail(Node* &head, Node* &tail, int value){
    Node* temp = new Node(value % 10);
    if(!head){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = tail->next;
    }
}
// approach 
// first reverse both Linkedlist
// add both linkedlist same ques like array add 2 digit;
// or write geniric code like below
// reverse answers linkedlist;

Node* addList(Node* head1, Node* head2){
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* newHead = NULL;
    Node* tail = NULL;

    int carry = 0;
    while(head1 || head2 || carry){
        int val1 = 0;
        if(head1) val1 = head1->data;

        int val2 = 0;
        if(head2) val2 = head2->data;

        int sum = carry + val1 + val2;

        insertTail(newHead,tail,sum);
        carry = sum / 10;

        if(head1) head1 = head1->next;
        if(head2) head2 = head2->next;
    }
    newHead = reverse(newHead);
    return newHead;
}

int main(){
    Node *head = NULL;
    Node *head1 = NULL;

    InsertHead(head,0);
    InsertHead(head,9);
    InsertHead(head,7);
    InsertHead(head,3);

    InsertHead(head1,4);
    InsertHead(head1,2);
    InsertHead(head1,1);

    print(head);
    print(head1);

    Node* newHead = addList(head,head1);
    print(newHead);

    return 0;
}