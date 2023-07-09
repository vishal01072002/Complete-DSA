#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 5
// Left Rotate the Array by One

int main()
{
    // =========== Optomal Approch ============
    // store arr[0] value
    // swap arr[i] and arr[i+1] element

    int arr[] = {1, 10, 1, 4, 2, 7, 3, 9, 3, 3};
    int n = 10;
    int temp = arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        swap(arr[i], arr[i + 1]);
    }
    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}