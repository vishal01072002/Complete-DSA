#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void printArr(vector<int>& arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
}

// ============ Insertion Sort Algorithim ==========

void insertionSort(vector<int>& arr, int n)
{   
    for(int i=1; i<n; i++){
        int currElement = arr[i];
        int j = i-1;
        while (j>=0)
        {
            if(currElement < arr[j]){
                arr[j+1] = arr[j];
            }   
            else{
                break;
            }   
            j--;
        }
        arr[j+1] = currElement;
    }
}


int main()
{
    vector<int> arr = {3 ,43 ,7 ,14 ,28 ,44 ,22 ,2 ,13 ,36 ,20 ,19 ,46 ,22 };
    insertionSort(arr,arr.size());
    printArr(arr);
   return 1;
}