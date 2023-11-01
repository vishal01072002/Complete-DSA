#include<iostream>
using namespace std;

// implementation of stack

class Stacks{
    int *arr;
    int size;
    int top = -1;

    public:
        Stacks(int s){
            size = s;
            arr = new int[s];
        }

        void push(int n){
            if(size - top > 1){
                // cout<<top <<" "<<size<<endl;
                arr[++top] = n;
            }
            else{
                cout << "stack overflow" << endl;
            }
        }

        void pop(){
            if(top >= 0){
                int val = arr[top--];
                cout << val << endl;
            }
            else{
                cout << "stack underflow" << endl;
            }
        }

        void peek(){
            if(top >= 0){
                cout << arr[top] << endl;
            }
            else{
                cout << "stack underflow" << endl;
            }
        }

        bool isEmpty(){
            return top < 0;
        }
};

int main(){
    Stacks st(3);
    cout<< st.isEmpty();

    st.push(1);
    st.push(2);
    st.push(3);
    
    cout<< st.isEmpty();
    st.peek();

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}