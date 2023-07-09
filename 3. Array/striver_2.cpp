#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 2
// Find Second Smallest and Second Largest Element in an +tive array

int main()
{
    // =========== Approch 1 ============
    // store and return 2nd last index  O(N logN)

    // =========== Approch 2 ============
    // find maximum by comparing each element
    // traverse array 2 times

    // =========== Optomal Approch ============
    // find maximum by comparing each element
    // and make 2 max1 max2 variable
    // max2 will be max in array but small than max 2

    int arr[] = {1, 3, 6, 4, 5, 9, 7};
    int n = 7;
    int max1 = -1;
    int max2 = -1;

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    if (n == 1)
    {
        return max2;
    }

    for (int i = 0; i < n; i++)
    {
        if (max1 < arr[i])
        {
            max2 = max1;
            max1 = arr[i];
        }
        if (max2 < arr[i] && arr[i] < max1)
        {
            max2 = arr[i];
        }

        // for 2nd minimum
        if (min1 > arr[i])
        {
            min2 = min1;
            min1 = arr[i];
        }

        if (min2 > arr[i] && arr[i] > min1)
        {
            min2 = arr[i];
        }
    }

    cout << max2 << " " << min2;
    return 0;
}