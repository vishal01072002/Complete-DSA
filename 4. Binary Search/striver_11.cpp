#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// STRIVER medium binary search ques 11
// Painter Partition problem

// =========== Optimal APPROCH ==========
// binary search 

int painterNeed(vector<int> &arr,int eachPainterTask){
    int painter = 1;
    int n = arr.size();
    long long int CurrentpainterDoneTask = 0;
    for(int i=0; i<n; i++){
        if(CurrentpainterDoneTask + arr[i] <= eachPainterTask){
            CurrentpainterDoneTask += arr[i];
        }
        else{
            painter++;
            CurrentpainterDoneTask = 0;
            CurrentpainterDoneTask = arr[i];
        }
    }
    return painter;
}


int painterPartition(vector<int> &arr, int size, int painter){

    int start = *max_element(arr.begin(),arr.end());
    int end = accumulate(arr.begin(),arr.end(),0);

    int mid = start + (end - start)/2;
    while(start <= end){

        int painterCount = painterNeed(arr,mid);
        if(painterCount <= painter){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int main()
{
    int n = 4;
    int m = 2;
    // vector<int> arr = {25,46,28,49,24};
    vector<int> arr = {12,34,67,90};

    if(n<m) return -1;
    int minn = painterPartition(arr, n,m);
    
    cout << minn << " " ;

    return 1;
}