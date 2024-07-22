#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Heapify algorithim / build heap
// for every node we apply heapify algo
// we dont need to process leaf node for heapify
// leafnodes = (N/2 + 1) to n
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

int main(){
    
    vector<int> arr = {-1,1,4,7,8,4,2,5,9};
    int n = arr.size(); 
    cout << n;
    for(auto i: arr){
        cout << i << " ";
    }

    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }

    for(auto i: arr){
        cout << i << " ";
    }

    return 0;
}