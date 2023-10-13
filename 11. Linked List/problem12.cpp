#include<iostream>
using namespace std;
#include<algorithm>

// Merge 2 sorted Linked List.

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

// approach 1 using 2  -- O(n)
// store count of each number 0, 1, 2 
// in second traverse change data 

// approach 2 With out chainging data / (change link only)
Node* merge(Node* head1, Node* head2){
    if(! head1) return head2;
    if(! head2) return head1;

    Node * minHead = NULL;
    if(head1->data < head2->data){
        minHead = head1;
        head1 = head1->next;
    }
    else{
        minHead = head2;
        head2 = head2->next;
    }
    Node* newHead = minHead;

    while (head1 && head2){
        if(head1->data <= head2->data){
            minHead->next = head1;
            head1 = head1->next;
        }
        else {
            minHead->next = head2;
            head2 = head2->next;
        }
        minHead = minHead->next;
    }

    // if any linked list is end but other is remaining
    
    minHead->next = (head1)? head1 : head2;
    return newHead;
}

int main(){
    Node *head = NULL;
    Node *head1 = NULL;

    InsertHead(head,10);
    InsertHead(head,9);
    InsertHead(head,7);
    InsertHead(head,3);
    InsertHead(head,2);
    InsertHead(head,1);
    InsertHead(head,1);

    InsertHead(head1,13);
    InsertHead(head1,8);
    InsertHead(head1,6);
    InsertHead(head1,4);
    InsertHead(head1,2);
    InsertHead(head1,0);
    print(head);
    print(head1);

    Node* newHead = merge(head,head1);
    print(newHead);

    return 0;
}