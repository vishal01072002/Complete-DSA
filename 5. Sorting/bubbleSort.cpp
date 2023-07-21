#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void printArr(vector<int>& arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
}

// ============ Bubble Sort Algorithim ==========

void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i=n-1; i>0; i--){
        bool swappedd = false;
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swappedd = true;
            }
        }
        if(!swappedd){
            break;
        }
    }
}


int main()
{
    vector<int> arr = {3 ,43 ,7 ,14 ,28 ,44 ,22 ,2 ,13 ,36 ,20 ,19 ,46 ,22 };
    bubbleSort(arr,arr.size());
    printArr(arr);
   return 1;
}