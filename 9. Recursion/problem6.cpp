#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// binary search in array
int binarySearch (int arr[], int start, int end, int key){
    if(start > end) return -1;
    
    int mid = start + (end - start)/2;
    if(key == arr[mid]) return 1;

    if(key < arr[mid]){
        // left part
        return binarySearch(arr, start, mid-1, key);
    }
    else{
        // right part
        return binarySearch(arr, mid+1, end, key);
    }
}


int main()
{
    int size = 10;
    int key = 69;
    int arr[size] = {1,4,6,9,11,16,19,20,26,69};
    int start = 0;
    int end = size - 1;
    int index = binarySearch(arr, start, end, key);
    cout<< "Is "<< key << " present in array " << index << endl;
    
    return 0;
}