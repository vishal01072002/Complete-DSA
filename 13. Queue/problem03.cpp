#include<iostream>
using namespace std;

// implementation of double ended queue

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

        void push_front(int data){
            if((front == 0 && rear == size-1) || front != 0 && rear == (front-1) % size ){
                cout << "queue overflow " << endl;
                return;
            }

            // first element is inserted
            if(front == -1){
                front = 0;
                rear = 0;
            }

            // if front on zero and rear in middle
            // cyclic nature 
            else if(front == 0 && rear != size-1){
                front = size-1;
            }
            else{
                front--;
            }
            arr[front] = data;
        }

        void push_back(int data){
            if((front == 0 && rear == size-1) || rear == (front-1) % size ){
                cout << "queue overflow " << endl;
                return;
            }

            // first element is inserted
            if(front == -1){
                front = 0;
                rear = 0;
            }

            // if front on zero and rear in middle
            // cyclic nature 
            else if(rear == size-1 && front != 0){
                rear = 0;
            }
            else{
                rear++;
            }
            arr[rear] = data;
        }

        int pop_front(){
            // if at time of pop front == rear then
            // re initialize both to 0
            if(front == -1){
                cout << "Queue underflow" << endl;
                return -1;
            }

            // if only one element
            int val = arr[front];
            arr[front] = -1;
            if(front == rear){
                front = rear = -1;
            }

            // cyclic nature
            else if(front == size-1){
                front = 0;
            }
            else{
                front++;
            }
            return val;            
        }

        int pop_back(){
            if(front == -1){
                cout << "Queue underflow" << endl;
                return -1;
            }

            // if only one element
            int val = arr[rear];
            arr[rear] = -1;
            if(front == rear){
                front = rear = -1;
            }

            // cyclic nature
            else if(rear == 0){
                rear = size-1;
            }
            else{
                rear--;
            }
            return val;
        }

        void front(){
            if(front == -1){
                cout << arr[front] << endl;
            }
            else{
                cout << "queue underflow" << endl;
            }
        }
        
        void rear(){
            if(front == -1){
                cout << arr[rear] << endl;
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