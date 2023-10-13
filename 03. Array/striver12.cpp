#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array medium Ques 1
// Two sum

int main()
{
    // =========== Approch ============
    // check every element O(N2)

    // =========== Optomal Approch ============
    // sort the array and then apply 2 pointer approach
    
    int arr[] = {4,1,2,3,1};
    int n = 5;
    int k = 5;
    pair <int,int> ans;

    sort(arr,arr+n);

    int i=0,j=n-1;
    while(i<j){
        int ele = arr[i]+arr[j];
        if(ele == k){
            cout<<i<<" "<<j;
            return 1;
        }
        else if(ele < k){
            i++;
        }
        else{
            j--;
        }
    }
    return 0;
}