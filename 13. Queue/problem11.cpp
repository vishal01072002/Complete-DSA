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

class NQueue{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;
    int n;
    int k;

    public:
        NQueue(int n, int k){
            this->n = n;
            this->k = k;
            arr = new int[n];
            next = new int[n];
            front = new int[k];
            rear = new int[k];

            // initialization 
            freeSpot = 0;

            for(int i=0; i<k; i++){
                front[i] = -1;
                rear[i] = -1;
            }
            
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        int push(int x, int m){
            // overflow
            if(freeSpot == -1){
                return -1;
            }

            // free index
            int index = freeSpot;

            // update free spot
            freeSpot = next[index];


            // first time
            if(front[m-1] == -1){
                front[m-1] = index;
            }
            else{
                // link prev element to new using next
                // prev rear to curr index link
                next[rear[m-1]] = index;
            }

            // update next index as no empty
            next[index] = -1;

            // update rear
            rear[m-1] = index;
            
            // update value
            arr[index] = x;
            return 1;
        }

        int pop(int m){
            if(front[m-1] == -1){
                cout << "stack underflow" << endl;
                return -1;
            }

            // find index of poped element
            int index = front[m-1];

            // update front using next
            // coz next store the addres of next element
            front[m-1] = next[index];
            
            // update freespot in next and also freespot to curr poped index
            next[index] = freeSpot;
            // update freeSpot 
            freeSpot = index;

            // extract value
            int value = arr[index];

            // return value
            return value;
        }
};

int main(){
    NQueue q(6,3);

    q.push(1,1);
    q.push(2,1);
    q.push(3,2);

    q.pop(1);
    q.pop(2);
    q.pop(2);
    q.pop(1);
    return 0;
}