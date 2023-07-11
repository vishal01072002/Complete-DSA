#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array medium Ques 3
// Two sum

int main()
{
    // =========== Approch ============
    // check every element subarray sum O(N2)

    // =========== Optomal Approch ============
    // kadans algo
    
    // int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int arr[] = {-7 ,-8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10};
    int n = 15;

    int maxi = INT_MIN;
    int sum = 0;
    int i=0;
    while(i<n){
        sum = sum + arr[i];
        maxi = max(sum,maxi);
        if(sum < 0){
            sum = 0;
        }
        i++;
    }
    cout<<maxi;
    return 0;
}