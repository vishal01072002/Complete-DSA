#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// STRIVER medium binary search ques 8
// Aggresive cow
// put cow in stalls with min distance for each two cows which is maximum possible

// =========== Optimal APPROCH ==========
// binary search

int cowNeed(vector<int> &arr, int size, int minDistance){
    int cow = 1;
    int lastCowIndx = 0;
    for(int i=1; i<size; i++){
        // >= minimum itna to ho 
        if(arr[i] - arr[lastCowIndx] >= minDistance){
            cow++;
            lastCowIndx = i;
        }
    }
    return cow;
}

int aggressiveCow(vector<int> &arr, int size, int k)
{
    int start = 1;
    int end = arr[size-1];
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end){
        //how many cow can be put in stalls
        int cowInStall = cowNeed(arr,size,mid);
        if(cowInStall < k){
            // distance ghatao cow nii aa pa rahi
            end = mid-1;
        }
        else{
            // cow aa gayi hai to distance bada kar dekho
            // coz we have to find maximum
            ans = mid;
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main()
{
    int n = 4;
    int m = 2;
    // vector<int> arr = {25,46,28,49,24};
    vector<int> arr = {12, 34, 67, 90};

    if (n < m)
        return -1;
    int minn = aggressiveCow(arr, n, m);

    cout << minn << " ";

    return 1;
}