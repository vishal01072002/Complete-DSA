#include<iostream>
#include<stack>
using namespace std;

// sort an stack

// print stack
void print(stack<int>s){
    while(!s.empty()){
        cout << (s.top()) << " ";
        s.pop();
    }
    cout << endl;
}

void sortElement(stack<int> &s, int num){
    if(s.empty() || s.top() <= num){
        s.push(num);
        return;
    }

    int val = s.top();
    s.pop();
    sortElement(s,num);
    s.push(val);
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int val = s.top();
    s.pop();
    sortStack(s);
    sortElement(s,val);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(7);
    s.push(2);
    s.push(6);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);
    //insertEnd1(s,5);
    //insertEnd2(s,10);
    sortStack(s);
    print(s);
}