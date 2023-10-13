#include<iostream>
using namespace std;
#include<vector>
#include<map>

// 5 way to remove cycle
// 3 way to detect

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

// detect cycle in Linked List.
// first approach use map <Node*,bool> to check visited or not

Node* isCycle(Node* head){
    if(!head){
        return head;
    }

    map<Node*,bool> visited;
    Node* temp = head;

    while(temp!= NULL){
        if(visited[temp]){
            cout << "cycle Present ";
            return temp;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return head;
}

// using floyd's cycle detection algorithim
Node* floydCycle(Node* head){
    if(!head || head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;

        if(slow == fast){
            break;
        }
    }
    return slow;
}

// find starting node of cycle
Node* cycleStart(Node* head){
    if(! head) return head;

    Node* intersect = floydCycle(head);
    Node* slow = head;

    while (slow != intersect)
    {
        slow = slow->next;
        intersect = intersect->next;
    }
    return slow;
}

// remove cycle from linked list
void removeCycle(Node* head){
    if(!head) return;

    Node* intersect = floydCycle(head);
    if(!intersect) return head; // for when cycle not present
    Node* slow = head;
    
    while (slow != intersect){
        slow = slow->next;
        intersect = intersect->next;
    }
    
    Node* start = slow;
    while (slow->next != start){
        slow = slow->next;
    }

    cout << prev->next->data;
    slow->next = NULL;
    return;
}

int main(){
    Node *head = NULL;

    InsertHead(head,6);
    InsertHead(head,5);
    InsertHead(head,4);
    InsertHead(head,3);
    InsertHead(head,2);
    InsertHead(head,1);

    // single element loop
    // head->next->next->next->next->next->next = head->next->next->next->next->next;

    head->next->next->next->next->next->next = head->next->next;
    isCycle(head);
    
    Node* ans = floydCycle(head);
    cout << ans->data <<endl;
    
    Node* start = cycleStart(head);
    cout << "cycle starting Node is " << start->data << endl;
    
    removeCycle(head);
    return 0;
}