#include<iostream>
#include<queue>
using namespace std;

// delete element from max heap
// i th node has left child at 2*i and right child at 2*i + 1
// 1. swap last element to root
// 2. delete last node
// 3. place root at right place


class Heap{
    int arr[100];

    public:

    int size;
    Heap(){
        this->size = 0;
        arr[0] = -1;
    }

    void inserts(int n){
        size++;
        int indx = size;
        arr[indx] = n;

        // make node at right place
        while(indx > 1){
            int parent = indx/2;
            if(arr[parent] < arr[indx]){
                swap(arr[parent],arr[indx]);
                indx = parent;
            }
            else{
                return;
            }
        }
    }

    int deletes(){
        if(size == 0){
            return -1;
        }

        int ele = arr[1];

        // swap with root
        arr[1] = arr[size];

        // delete last node
        size--;

        // make it place
        int indx = 1;
        int leftChild = 2*indx ;
        int rightChild = 2*indx + 1;

        int indx1 = indx;
        int indx2 = indx;

        while(indx1 < size && leftChild <= size && arr[indx1] < arr[leftChild]){
            swap(arr[indx1],arr[leftChild]);
            indx1 = leftChild; // 1 2 3
        }
        while(indx2 < size && rightChild <= size && arr[indx2] < arr[rightChild]){
            swap(arr[indx2],arr[rightChild]);
            indx2 = rightChild; // 1 2 3
        }
        
        cout<< "- "<< ele << "- " <<endl;
        return ele;
    }

    void printHeap(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int main(){
    Heap maxheap;

    maxheap.inserts(3);
    maxheap.inserts(6);
    maxheap.inserts(2);
    maxheap.inserts(4);
    maxheap.inserts(11);
    maxheap.inserts(10);
    maxheap.inserts(12);
    maxheap.inserts(16);

    maxheap.printHeap();

    maxheap.deletes();
    maxheap.printHeap();
    maxheap.deletes();
    maxheap.printHeap();
    maxheap.deletes();
    maxheap.printHeap();
    maxheap.deletes();
    maxheap.printHeap();
    maxheap.deletes();
    maxheap.printHeap();
    maxheap.deletes();
    maxheap.printHeap();
    maxheap.deletes();

    return 0;
}