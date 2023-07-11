#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 10
// Missing Number

int main()
{
    // =========== Optimal Approch 1 ============
    // find total sum from 1 to N
    // using (n*(n+1))/2
    // find sum of array
    // subtract array sum from total sum

    // =========== Optomal Approch ============
    // find XOR of number from 1 to N
    // find XOR of array element

    int arr[] = {1, 2, 3, 4, 5,0, 7};
    int ans = 0;
    int n = 7;

    for (int i = 1; i <= n; i++)
    {
        ans = ans ^ i;
        ans = ans ^ arr[i - 1];
        cout<< arr[i-1];
    }

    cout << ans;
    return 0;
}