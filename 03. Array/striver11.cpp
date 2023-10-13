#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 11
// Longest Subarray with given Sum K(Positives and zeros)
int main()
{

    // =========== Approch ============
    // check every subarray with sum k O(N2)
    // for i to n
    //  { for i to n   ==> if sum == k break that loop}

    // =========== Optomal Approch ============
    // kadane 's algorithm
   

    // int a[] = {1, 0, -2, 1, 2, 1, 0, 0, 1};
    int a[] = {-1, 0, 1, 1, -1, -1, 0};
    // int a[] = {1,2,1,3};
    int size = 7;
    int k = 0;
    int length = 0;
    int sum = 0;

    int i = 0, j = -1;
    while (j < size)
    {
        if (sum <= k)
        {
            if (sum == k)
            {
                length = max(length, j - i + 1);
            }
            j++;
            sum = sum + a[j];
            cout << sum << " " << i << " " << j << endl;
        }
        else // if (sum > k)
        {
            sum = sum - a[i];
            i++;
            cout << sum << " yo " << i << " " << j << endl;
        }
    }

    cout << length;

    return 0;
}