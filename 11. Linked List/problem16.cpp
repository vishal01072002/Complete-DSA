#include<iostream>
using namespace std;
#include<algorithm>

// Merge sort on Linked List.

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

Node* slowFast(Node* head){
    if(!head) return NULL;
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

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

Node* mergesort(Node* head){
    // base condition for NULL and single element
    if(!head || !head->next) return head;

    // break linked list in to 2 part
    Node* mid = slowFast(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // recursive call
    left = mergesort(left);
    right = mergesort(right);

    // merge both sorted list
    head = merge(left,right);
    return head;
}

int main(){
    Node *head = NULL;

    InsertHead(head,9);
    InsertHead(head,2);
    InsertHead(head,6);
    InsertHead(head,10);
    InsertHead(head,7);
    InsertHead(head,8);
    InsertHead(head,3);
    print(head);

    Node* newHead = mergesort(head);
    print(newHead);

    return 0;
}