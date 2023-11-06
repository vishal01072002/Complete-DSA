#include<iostream>
#include<stack>
using namespace std;

// implement Queue using stack
void printque(stack<int> q){
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout<<endl;
}

class queues{
    stack<int> s1;
    stack<int> s2;

    public:
    
    void push(int x){
        if(!isempty()){
        //    cout<< "overflow" << endl;
        }

        if(!s2.empty()){
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        s1.push(x);
    }

    int pop(){
        if(isempty()){
            cout<< "underflow" <<endl;
            return -1;
        }

        if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        cout<< val <<endl;
        s2.pop();
        return val;
    }

    bool isempty(){
        if(s1.empty() && s2.empty()){
            return 1;
        }
        return 0;
    }
};

int main(){
    queues q(5) ;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.pop();
    return 0;
}