#include<iostream>
using namespace std;

// implementation N number of stack in an Array
// 5 step
// 1. find free index
// 2. update freespot
// 3. push value
// 4. update next array to previous top index
// 5. update top array to new index index

// pop is just reverse of these steps

class Stacks{
    int *arr;
    int *top;
    int *next;
    int freeSpot;
    int n;

    public:
        Stacks(int s, int N){
            n = s;
            arr = new int[s];
            next = new int[s];
            top = new int[N];

            // initialization 
            freeSpot = 0;

            for(int i=0; i<N; i++){
                top[i] = -1;
            }
            
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        int push(int n, int m){
            // overflow
            if(freeSpot == -1){
                return -1;
            }

            // free index
            int index = freeSpot;

            // update free spot
            freeSpot = next[index];

            // update value
            arr[index] = n;

            // update next array
            next[index] = top[m-1];

            // update top
            top[m-1] = index;

            return 1;
        }

        int pop(int m){
            if(top[m-1] == -1){
                cout << "stack underflow" << endl;
                return -1;
            }

            // find index of poped element
            int index = top[m-1];

            // reverse of push

            // update top
            top[m-1] = next[index];
            
            // update next array to next free spot
            next[index] = freeSpot;

            // extract value
            int value = arr[index];

            // update freeSpot 
            freeSpot = index;

            // return value
            return value;
        }

        
};

int main(){
    Stacks st(6,3);

    st.push(1,1);
    st.push(2,1);
    st.push(3,2);

    st.pop(1);
    st.pop(2);
    st.pop(2);
    st.pop(1);
    return 0;
}