#include<iostream>
using namespace std;
#include<algorithm>

// Sort 0, 1 & 2 in a Linked List.

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
void sort012(Node* &head){

    // dummy Node
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // make seprate List of 0,1,2
    Node* curr = head;
    while(curr){
        if(curr->data == 0){
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        }
        else if(curr->data == 1){
            oneTail->next = curr;
            oneTail = oneTail->next;
        }
        else if(curr->data == 2){
            twoTail->next = curr;
            twoTail = twoTail->next;
        }
        curr = curr->next;
    }

    // merge lists

    // 1's list is empty
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }

    // 1's list is not empty
    else {
        zeroTail->next = twoHead->next; 
    }

    // handle 1's list
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // return new head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return;
}

int main(){
    Node *head = NULL;

    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,0);
    InsertHead(head,0);
    InsertHead(head,2);
    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,0);
    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,1);
    InsertHead(head,1);
    print(head);

    sort012(head);
    print(head);

    return 0;
}