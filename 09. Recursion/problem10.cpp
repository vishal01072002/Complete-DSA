#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Bubble Sort in array
void bubbleSort (int arr[], int size){
    if(size == 0 || size == 1){
        return ;
    }

    for(int i=0; i<size-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    
    bubbleSort(arr, size-1);
}


int main()
{
    int size = 8;
    int arr[size] = {11,5,35,57,7,45,6,3};
    
    bubbleSort(arr,size);
    cout<< "array after sort " << endl;
    for(auto &i: arr){
        cout<< i << " ";
    }
    
    return 0;
}