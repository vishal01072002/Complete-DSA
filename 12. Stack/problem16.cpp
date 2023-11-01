#include<iostream>
#include<stack>
using namespace std;

// implementation a special stack that return minimum of stack 
// only in O(1) time and space compexity

class Stacks{
    stack<int> s;
    int mini;

    public:

        void push(int curr){
            // check if it is first element
            if(s.empty()){
                st.push(curr);
                mini = curr;
            }
            else{
                if(curr < mini){
                    int value = 2*curr - mini;
                    s.push(value);
                    mini = curr;
                }
                else{
                    s.push(curr);
                }
            }
        }

        int pop(){
            if(s.empty()){
                // underflow
                return -1; 
            }
            else{
                int curr = s.top();
                s.pop();
                if(curr < mini){
                    int prevmini = 2*mini - curr;
                    int value = mini;
                    mini = prevmini;
                    return value;
                }
                else{
                    return curr;
                }
            }
        }

        int top(){
            if(s.empty()){
                // underflow
                return -1; 
            }
            else{
                int curr = s.top();
                if(curr < mini){
                    return mini;
                }
                else{
                    return curr;
                }
            }
        }

        int mini(){
            if(s.empty()){
                // underflow
                return -1; 
            }
            else{
                return mini;
            }
        }
};

int main(){
    Stacks st();

    st.push(1);
    st.push(2);
    st.push(3);

    st.pop(1);
    st.pop(2);
    st.pop(2);
    st.pop(1);
    return 0;
}