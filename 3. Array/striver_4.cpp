#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 4
// Remove Duplicates in-place from Sorted Array

int main()
{
    // =========== Approch 1 ============
    // store in SET O(N logN) (coz of set)
    // not store duplicate

    // =========== Optomal Approch ============
    // 2 pointer approch
    // i and j start from 0
    // if (ele[i] == ele[j])  => j++
    // if (ele[i] < ele[j] )  => i++  , swap  , j++
    // OR    if (ele[i] != ele[j] )  => i++  , swap  , j++

    int arr[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 3};
    int n = 10;
    int i = 0, j = 0;

    while (j < n)
    {
        if (arr[i] == arr[j])
        {
            j++;
        }
        else if (arr[i] < arr[j])
        {
            i++;
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "ans " << i + 1; // lenght of new array
    return 0;
}