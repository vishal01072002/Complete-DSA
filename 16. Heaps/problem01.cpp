#include<iostream>
#include<queue>
using namespace std;

// insert element in max heap
// i th node has left child at 2*i and right child at 2*i + 1
// insert T.C = O(1)
// put at right place T.C = O(logN)

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

    void printHeap(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
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
    return 0;
}