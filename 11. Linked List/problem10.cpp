#include<iostream>
using namespace std;
#include<algorithm>
#include<map>

// Remove duplicates from Not sorted Linked List.

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

// approach 1 using 2 loop -- O(n2)
void removeDuplicate1(Node* &head){
    if(!head) return;
    
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr;
        while(temp && temp->next){
            if(curr->data == temp->next->data){
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}

// approach 2 using map loop -- O(nLog(n) + O(n))
void removeDuplicate2(Node* &head){
    if(!head) return;
}

// approach 3 first sort and then 2 Pointer loop -- O(n2)
void removeDuplicate3(Node* &head){
    if(!head) return;
    
    map<int,bool> visit;

    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        int num = curr->data;
        if(visit[num]){
            prev->next = curr->next;
        }
        visit[num] = 1;
        prev = curr;
        curr = curr->next;
    }
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
        head = head->next;
    }
    return ;
}

// by change node pointer
void removeDuplicate3(Node* head){
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

    InsertHead(head,3);
    InsertHead(head,7);
    InsertHead(head,6);
    InsertHead(head,2);
    InsertHead(head,5);
    InsertHead(head,4);
    InsertHead(head,3);
    InsertHead(head,2);
    InsertHead(head,2);
    InsertHead(head,1);
    InsertHead(head,1);
    print(head);

    removeDuplicate2(head);
    // removeDuplicate2(head);
    print(head);

    return 0;
}