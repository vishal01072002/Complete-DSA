#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void printArr(vector<int>& arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
}

// ============ Selection Sort Algorithim ==========

void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i=0; i<n-1; i++){
        int minValueIndx = i;
        for(int j=i+1; j<n; j++){
            if(arr[minValueIndx] > arr[j]){
                minValueIndx = j;
            }
        }
        swap(arr[i],arr[minValueIndx]);
    }
}


int main()
{
    vector<int> arr = {3 ,43 ,7 ,14 ,28 ,44 ,22 ,2 ,13 ,36 ,20 ,19 ,46 ,22 };
    selectionSort(arr,arr.size());
    printArr(arr);
   return 1;
}