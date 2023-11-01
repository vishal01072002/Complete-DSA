#include<iostream>
#include<stack>
using namespace std;

// Delete middle element from stack
// for odd length  -- N=5 remove  (N/2 + 1) = 3rd
// for even length  -- N=6 remove  (N/2 + 1) = 4rd


// print stack
void print(stack<int>s){
    while(!s.empty()){
        cout << (s.top()) << " ";
        s.pop();
    }
    cout << endl;
}
// iterative approch
void removeMid(stack<int> &s){

    // take extra stack for store poped elements
    stack<int> temp;
    int size = s.size();
    int eleCount = 0;
    int mid = ((size/2) + 1);

    // store all element before middle
    while(eleCount < mid){
        temp.push(s.top());
        s.pop();
        eleCount++;
    }

    // remove middle element
    temp.pop();

    // insert all rest element
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}

// recursive approach
void removeMiddle(stack<int> &s, int count, int mid){
    if(count == mid){
        s.pop();
        return;
    }

    int val = s.top();
    s.pop();
    removeMiddle(s,count+1,mid);
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

    int size = s.size();
    int mid = (size/2) + 1;

    print(s);
    // removeMid(s);
    removeMiddle(s,1,mid);
    print(s);
}