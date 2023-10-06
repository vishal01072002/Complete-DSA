#include<iostream>
using namespace std;
#include<vector>

// reverse an Linked List in K group
bool perfectLength(Node* head,int k){
        int len = 0;
        while(head != NULL && len <= k){
            head = head->next;
            len++;
        }
        if(len < k){
            return 0;
        }
        return 1;
}

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

Node* KreverseList(Node* &head, int k){
    if(head == NULL){
        return head;
    }

    // first reverse K elements
    int count = 0;
    Node* prev = NULL;
    Node* curr = head;
    Node* temp ;

    if(!perfectLength(head,k)){
        return head;
    }

    while (count < k && curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    
    Node* reverseHead = KreverseList(temp,k);
    head->next = reverseHead;
    return prev;
}

int main(){
    Node *head = NULL;

    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,3);
    InsertHead(head,4);
    InsertHead(head,5);

    print(head);

    KreverseList(head);
    print(head);

    return 0;
}