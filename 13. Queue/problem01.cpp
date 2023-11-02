#include<iostream>
using namespace std;

// implementation of queue
// for full rear == N-1;
// for empty front  == rear;

class Queue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
        Queue(int s){
            size = s;
            arr = new int[s];
            front = 0;
            rear = 0;
        }

        void enqueue(int data){
            if(rear == size){
                cout << "queue overflow " << endl;
                return; 
            }
            
            arr[rear] = data;
            rear++;
        }

        int dequeue(){
            // if at time of pop front == rear then
            // re initialize both to 0
            if(front == rear){
                cout << "Queue underflow" << endl;
                return -1;
            }
            else{
                int val = arr[front];
                arr[front] = -1;
                front++;

                // at last if queue is empty after pop
                // re initialize
                if(front == rear){
                    front = 0;
                    rear = 0;
                }
                return val;
            }
        }

        void front(){
            if(front != rear){
                cout << arr[front] << endl;
            }
            else{
                cout << "queue underflow" << endl;
            }
        }

        bool isEmpty(){
            return front == rear;
        }
};

int main(){
    
    return 0;
}