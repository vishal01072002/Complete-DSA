#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// striver array easy Ques 3
// Check if an Array is Sorted

int main(){

    // =========== Optomal Approch ============
    // check 2 consecutive value are sorted or not
    // arr[i] <= arr[i+1];

    int arr[] = {1,3,4,6,6,9,10};
    int n = 7;

    int i = 0;
    while(i < n-1){
        if (!(arr[i] < arr[i+1])){
            cout<<"not sorted";
            return 0;
        }
        i++;
    }
    cout<<"sorted";
    return 1;

    return 0;
}