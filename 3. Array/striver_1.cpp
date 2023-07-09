#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// striver array easy Ques 1
// Largest Element in an Array

int main(){
    // =========== Approch 1 ============
    // store and return last index  O(N logN)

    // =========== Optomal Approch ============
    // find maximum by comparing each element

    int arr[] = {1,3,5,7,9};
    int n = 5;

    int max = INT_MIN;

    for(int i=0 ; i<n; i++){
        max = (max < arr[i])? arr[i] : max;
    }

    cout<< max;
    return 0;
}