#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(int *arr ,int s, int e){
    // for put ele at place where left side is small and right is greater

    int element = arr[s];
    int count = 0;
    int eleIndx;
    // find all small number to find right place for element
    for (int i = s+1; i <= e; i++){
        if(arr[i] <= element){
            count++;
        }
    }
    eleIndx = s+count;
    swap(arr[s],arr[eleIndx]);
    
    // two pointer to all small at left and greater to right
    int i=s, j=e;
    while(i < eleIndx && j > eleIndx){
        while(arr[i] <= element){
            i++;
        }
        while(arr[j] > element){
            j--;
        }

        if(i < eleIndx && j > eleIndx){
            swap(arr[i],arr[j]);
            i++; j--;
        }
    }
    return eleIndx;
}

// Merge Sort in array
void quickSort (int arr[],int start , int end){
    
    if(start >= end){
        // single element is already sorted
        return;
    }

    int pivote;
    pivote = partition(arr, start, end);

    //sort left part
    quickSort(arr, start, pivote-1);

    // sort right part
    quickSort(arr, pivote+1, end);

}


int main()
{
    int size = 8;
    int arr[size] = {11,5,35,57,7,45,6,3};
    
    quickSort(arr,0,size-1);
    cout<< "array after sort " << endl;
    for(auto &i: arr){
        cout<< i << " ";
    }
    
    return 0;
}