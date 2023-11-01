#include<iostream>
using namespace std;

// implementation two stack using array

class Stacks{
    int *arr;
    int size;
    int top1;
    int top2;

    public:
        Stacks(int s){
            size = s;
            arr = new int[s];
            top1 = -1;
            top2 = s;
        }

        void push1(int n){
            if(top2 - top1 > 1){
                arr[++top1] = n;
            }
            else{
                cout << "stack overflow" << endl;
            }
        }

        void push2(int n){
            if(top2 - top1 > 1){
                arr[--top2] = n;
            }
            else{
                cout << "stack overflow" << endl;
            }
        }

        void pop1(){
            if(top1 >= 0){
                int val = arr[top1--];
                cout << val << endl;
            }
            else{
                cout << "stack underflow" << endl;
            }
        }
        
        void pop2(){
            if(top2 < size){
                int val = arr[top2++];
                cout << val << endl;
            }
            else{
                cout << "stack underflow" << endl;
            }
        }

        void peek1(){
            if(top1 >= 0){
                cout << arr[top1] << endl;
            }
            else{
                cout << "stack underflow" << endl;
            }
        }
        
        void peek2(){
            if(top2 < size){
                cout << arr[top2] << endl;
            }
            else{
                cout << "stack underflow" << endl;
            }
        }
};

int main(){
    Stacks st(3);

    st.push1(1);
    st.push1(2);
    st.push2(3);
    
    st.peek1();

    st.pop1();
    st.pop1();
    st.pop2();
    st.pop2();
    return 0;
}