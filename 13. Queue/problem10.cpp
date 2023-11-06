#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// interleave the first and second half of queue N is even
// eg  -  1,2,3,4,5,6
//  ===>  1,4,2,5,3,6

void printque(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout<<endl;
}

// approach 1 using another queue
void method1(queue<int> q){
    queue<int> temp;

    // insert first half element
    int size = q.size();
    for(int i=0; i<((size+1)/2); i++){
        temp.push(q.front());
        q.pop();
    }

    // insert in orignal queue at alternate manner
    for(int i=0; i<((size+1)/2); i++){
        q.push(temp.front());
        q.push(q.front());

        temp.pop();
        q.pop();
    }

    printque(q);
}

// approach 2 constrain use only stack
void method2(queue<int> q){
    stack<int> temp;

    // insert first half element in stack these will be reverse
    int size = q.size();
    for(int i=0; i<((size+1)/2); i++){
        temp.push(q.front());
        q.pop();
    }

    // push first half in reverse order in queue
    while(!temp.empty()){
        q.push(temp.top());
        temp.pop();
    }

    // push in last to all second half
    for(int i=((size+1)/2); i<size; i++){
        q.push(q.front());
        q.pop();
    }

    // for make in order we need to reverse them one more time in stack
    for(int i=0; i<((size+1)/2); i++){
        temp.push(q.front());
        q.pop();
    }

    // insert in orignal queue at alternate manner
    while(!temp.empty()){
        q.push(temp.top());
        q.push(q.front());

        temp.pop();
        q.pop();
    }

    printque(q);
}


int main(){
    queue<int> q ;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    printque(q);

    method1(q);
    //printque(q);
    
    method2(q);
    //printque(q);

    return 0;
}