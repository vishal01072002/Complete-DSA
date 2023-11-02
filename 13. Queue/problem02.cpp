#include<iostream>
using namespace std;

// implementation of Circular Queue

class Queue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
        Queue(int s){
            size = s;
            arr = new int[s];
            front = -1;
            rear = -1;
        }

        void enqueue(int data){
            // 3case for insert 
            // a. first time 
            // b. simple 
            // c. rear at end and front in middle
            if((front == 0 && rear == size-1) || rear == ((front-1) % size)){
                cout << "queue overflow " << endl;
                return; 
            }
            else if(front == -1){
                rear++;
                front++;
                arr[rear] = data;
            }
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[rear] = data;
            }
            else{
                rear++;
                arr[rear] = data;
            }
        }

        int dequeue(){
            // re initialize both to 0
            if(front == -1){
                cout << "Queue underflow" << endl;
                return -1;
            }

            int value = arr[front];
            arr[front] = -1;

            // if single element removed
            if(front == rear){
                front = -1;
                rear = -1;
            }

            // if rear on last and front in middle
            else if(front == size-1){
                front = 0;
            }
            else{
                front++;
            }
            return val;
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