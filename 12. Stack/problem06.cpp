#include<iostream>
#include<stack>
using namespace std;

// Insert element in bottom of stack

// print stack
void print(stack<int>s){
    while(!s.empty()){
        cout << (s.top()) << " ";
        s.pop();
    }
    cout << endl;
}
// iterative approch
void insertEnd1(stack<int> &s, int num){

    // take extra stack for store poped elements
    stack<int> temp;
    int size = s.size();
    int eleCount = 0;
    int mid = ((size/2) + 1);

    // empty the stack to put in bottom
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }

    // add element in bottom
    temp.push(num);

    // insert all rest element
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}

// recursive approach
void insertEnd2(stack<int> &s, int num){
    if(s.empty()){
        s.push(num);
        return;
    }

    int val = s.top();
    s.pop();
    insertEnd2(s,num);
    s.push(val);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    print(s);
    //insertEnd1(s,5);
    insertEnd2(s,10);
    print(s);
}