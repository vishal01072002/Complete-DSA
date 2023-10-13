#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// sum of array
int arrSum (int arr[], int size){
    if(size == 1){
        return *(arr);
    }
    
    int sum = *(arr);
    int restArrSum = arrSum(arr+1, size-1);
    return sum + restArrSum;
}

// Check array is sorted or not
bool isSorted(int *arr, int size){
    if(size <= 1){
        return 1;
    }

    if(*arr > *(arr+1)){
        return false;
    }

    bool restArr = isSorted(arr+1,size-1);
    
    return restArr;
}



int main()
{
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    
    int sum = arrSum(arr,size);
    cout<< "sum of array is " << sum << endl;

    cout<<"Is given array sorted " << isSorted(arr,size) << endl;
    
    return 0;
}