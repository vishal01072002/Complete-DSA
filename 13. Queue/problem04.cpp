#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// reverse a Queue
// approach 1 using stack fifo property
// approach 2 using recursion
void printque(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q ;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    printque(q);

    stack<int> s;

    // insert in stack
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    
    // pop in reverse manner
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    printque(q);
    return 0;
}