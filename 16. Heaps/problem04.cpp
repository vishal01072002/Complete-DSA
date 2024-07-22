#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Heap Sort algorithim
// 1. swap last element to root
// 2. delete last node
// 3. heapify on root node
// i th node has left child at 2*i and right child at 2*i + 1

void heapify(vector<int> &arr, int n, int indx){
    int largest = indx;
    int left = 2*indx;
    int right = 2*indx + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != indx){
        swap(arr[largest],arr[indx]);
        heapify(arr,n,largest);
    }
}

void heapSort(vector<int> &arr, int n){
    int size = n;
    while(size > 1){
        swap(arr[size],arr[1]);

        size--;

        heapify(arr,size,1);
    }
}
int main(){
    
    vector<int> arr = {-1,1,4,7,8,4,2,5,9};
    int n = arr.size(); 
    //cout << n;
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;

    // make max heap
    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }

    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;

    heapSort(arr,n-1);
    
    for(auto i: arr){
        cout << i << " ";
    }

    return 0;
}