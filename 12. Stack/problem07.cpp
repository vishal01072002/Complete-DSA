#include<iostream>
#include<stack>
using namespace std;

// reverse an stack

// print stack
void print(stack<int>s){
    while(!s.empty()){
        cout << (s.top()) << " ";
        s.pop();
    }
    cout << endl;
}

void insertEnd(stack<int> &s, int num){
    if(s.empty()){
        s.push(num);
        return;
    }

    int val = s.top();
    s.pop();
    insertEnd(s,num);
    s.push(val);
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int val = s.top();
    s.pop();
    reverseStack(s);
    insertEnd(s,val);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    print(s);
    reverseStack(s);
    print(s);
}