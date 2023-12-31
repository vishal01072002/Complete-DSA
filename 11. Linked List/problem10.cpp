#include<iostream>
using namespace std;
#include<algorithm>
#include<map>
#include<unordered_set>

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

// approach 1 using 2  -- O(n2)
void removeDuplicate1(Node* &head){
    if(!head) return;
    
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr;
        while(temp && temp->next){
            if(curr->data == temp->next->data){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

// approach 2 using map  -- O(n)
void removeDuplicate2(Node* &head){
    if(!head) return;
    
    map<int,bool> visit;

    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        int num = curr->data;
        if(visit[num]){
            cout<<num;
            prev->next = curr->next;
        }
        else{
            visit[num] = 1;
            prev = curr;
        }
        curr = curr->next;
    }
}

// approach 3 using set loop -- O(n)
void removeDuplicate2(Node* &head){
    if(!head) return;
    
    unordered_set<int> visit;

    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        int num = curr->data;
        if(visit.find(num) != s.end()){
            cout<<num;
            prev->next = curr->next;
        }
        else{
            visit.insert(num);
            prev = curr;
        }
        curr = curr->next;
    }
}

// approach 3 first sort and then 2 Pointer loop -- O(nLog(n) + O(n))
// 2 pointer is down
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

int main(){
    Node *head = NULL;

    InsertHead(head,-1);
    InsertHead(head,3);
    InsertHead(head,7);
    InsertHead(head,6);
    InsertHead(head,2);
    InsertHead(head,3);
    InsertHead(head,2);
    InsertHead(head,4);
    InsertHead(head,3);
    InsertHead(head,2);
    InsertHead(head,3);
    InsertHead(head,1);
    print(head);

    removeDuplicate2(head);
    // removeDuplicate2(head);
    print(head);

    return 0;
}