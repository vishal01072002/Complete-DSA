#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// reverse first K element of Queue
// approach 
// using stack fifo property reverse K element and push in queue
// rest element which will come in front 
// pop them and insert from back
void printque(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    int k = 3;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    printque(q);
    int n = q.size();
    stack<int> s;

    // insert in stack
    int i=0;
    while(i<k){
        s.push(q.front());
        q.pop();
        i++;
    }
    
    // pop in reverse manner
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // insert at end the rest element
    i=0;
    while(i<n-k){
        q.push(q.front());
        q.pop();
        i++;
    }

    printque(q);
    return 0;
}