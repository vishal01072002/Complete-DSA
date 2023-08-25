#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int *arr ,int s, int e){
    int mid = s + (e-s)/2;

    // find  length of both array
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // use extra space
    int * first = new int[len1];
    int * second = new int[len2];

    // copy array in above temp array
    int k = s;
    
    for (int i = 0; i < len1; i++){
        first[i] = arr[k++];
    }

    for (int i = 0; i < len2; i++){
        second[i] = arr[k++];
    }
    
    // algo for merge to 2 sorted array
    k = s;
    int i = 0;
    int j = 0;
    while(i<len1 && j<len2){
        if(first[i] < second[j]){
            arr[k] = first[i++];
        }
        else{
            arr[k] = second[j++];
        }
        k++;
    } 

    while (i<len1)
    {
        arr[k++] = first[i++];
    }
    
    while(j < len2){
        arr[k++] = second[j++];
    }

    delete []first;
    delete []second;
}

// Merge Sort in array
void mergeSort (int arr[],int start , int end){
    
    if(start >= end){
        // single element is already sorted
        return;
    }
    int mid = start + (end-start)/2;
    //sort left part
    mergeSort(arr, start, mid);

    // sort right part
    mergeSort(arr, mid+1, end);

    merge(arr, start, end);
}


int main()
{
    int size = 8;
    int arr[size] = {11,5,35,57,7,45,6,3};
    
    mergeSort(arr,0,size-1);
    cout<< "array after sort " << endl;
    for(auto &i: arr){
        cout<< i << " ";
    }
    
    return 0;
}