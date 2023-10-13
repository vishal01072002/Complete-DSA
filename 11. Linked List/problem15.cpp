#include<iostream>
using namespace std;
#include<algorithm>
#include<unordered_map>

// // Copy List with Random Pointer
// leetcode 138

void insertTail(Node* &head, Node* &tail, int value){
    Node* temp = new Node(value);
    if(!head){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = tail->next;
    }
}

// approach 1 
// T.C = O(n)
// S.C = O(n)
Node* makeCopy(Node* head,){
    if(!head) return NULL;
    
    // first make copy of single list
    Node* newHead = NULL;
    Node* tail = NULL;
    Node* temp = head;
    while(temp){
        insertTail(newHead,tail,temp->val);
        temp = temp->next;
    }

    // create mapping
    unordered_map<Node*, Node*> oldToNew;
    temp = head;
    Node* temp2 = newHead;
    while(temp && temp2){
        oldToNew[temp] = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }

    // connect random link
    temp = head;
    temp2 = newHead;
    while(temp && temp2){
        temp2->random = oldToNew[temp->random];
        temp = temp->next;
        temp2 = temp2->next;
    }

    return newHead;
}

// approach 2 
// T.C = O(n)
// S.C = O(1)
Node* copyList(Node* head){
    if(! head) return NULL;

    // first make copy of single list
    Node* newHead = NULL;
    Node* tail = NULL;
    Node* temp = head;
    while(temp){
        insertTail(newHead,tail,temp->val);
        temp = temp->next;
    }

    // create mapping by putting clone node between orignal node 
    Node* orignal = head;
    Node* cloned = newHead;
    temp = NULL;
    Node* temp2 = NULL;
    while(orignal && cloned){
        temp = orignal->next;
        temp2 = cloned->next;
        orignal->next = cloned;
        cloned->next = temp;
        orignal = temp;
        cloned = temp2;
    }

    // connect random link
    orignal = head;
    cloned = newHead;
    while(orignal && cloned){
         if(orignal->random)
            cloned->random = orignal->random->next;
        orignal = orignal->next->next;
        if(cloned->next)
            cloned = cloned->next->next;
    }

    //reverte the mapping
    orignal = head;
    cloned = newHead;
    while(origal && cloned){
        orignal->next = cloned->next;
        if(cloned->next)
            cloned->next = cloned->next->next;
            
        orignal = orignal->next;
        cloned = cloned->next;
    }
    return newHead;
}
int main(){
    
    return 0;
}