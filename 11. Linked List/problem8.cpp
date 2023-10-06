#include<iostream>
using namespace std;
#include<vector>
#include<map>

// detect cycle in Linked List.

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

// first approach use map <Node*,bool> to check visited or not

bool isCycle(Node* head){
    if(!head){
        return 0;
    }

    map<Node*,bool> visited;
    Node* temp = head;

    while(temp!= NULL){
        if(visited[temp]){
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
}

int main(){
    Node *head = NULL;

    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,3);
    InsertHead(head,4);
    InsertHead(head,5);
    InsertHead(head,6);

    head->next->next->next->next->next->next = head->next->next->next;
    cout << isCycle(head);

    return 0;
}