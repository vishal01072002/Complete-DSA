#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 6
// Rotate array by K elements
// left and right rotate

void reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    // =========== Approch 1 ============
    // temprory store k value and then shift all other value

    // =========== Optomal Approch left rotation ============
    // k = 3
    // [1,3,7,8,9,10,11,12]
    // reverse whole array
    // [12,11,10,9,8  ,  7,3,1]
    // reverse last k element   and  first n-k element
    // index last k ==> N-k to N-1 index
    // [8,9,10,11,12  ,  1,3,7]

    // =========== Optomal Approch right rotation ============
    // reverse whole array
    // [12,11,10  ,  9,8,7,3,1]
    // reverse first k element   and  last n-k element
    // index first k ==> 0 to k-1 index
    // [10,11,12  ,  1,3,7,8,9]

    int arr1[] = {1, 3, 7, 8, 9, 10, 11, 12};
    int arr2[] = {1, 3, 7, 8, 9, 10, 11, 12};
    int n = 8;
    int k = 3;
    k = k % n;

    // left rotation
    reverse(arr1, 0, n - 1);
    // reverse first n-k and last k part
    reverse(arr1, 0, n - k - 1);
    reverse(arr1, n - k, n - 1);

    // right rotation
    reverse(arr2, 0, n - 1);
    // reverse first k and last N-k part
    reverse(arr2, 0, k - 1);
    reverse(arr2, k, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";

    cout << endl;

    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";

    return 0;
}