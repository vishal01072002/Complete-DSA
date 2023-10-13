#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// STRIVER medium binary search ques 11
// Split Array Largest Sum

// =========== Optimal APPROCH ==========
// binary search
int split(vector<int> &arr, int n, int maxSum)
{
    int split = 1;
    long long int currSubArrSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (currSubArrSum + arr[i] <= maxSum)
        {
            currSubArrSum += arr[i];
        }
        else
        {
            split++;
            currSubArrSum = 0;
            currSubArrSum = arr[i];
        }
    }
    return split;
}

int largeSum(vector<int> &arr, int size, int k)
{
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int numOfSplit = split(arr, size, mid);
        if (numOfSplit <= k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    int n = 4;
    int m = 2;
    // vector<int> arr = {25,46,28,49,24};
    vector<int> arr = {12, 34, 67, 90};

    if (n < m)
        return -1;
    int minn = largeSum(arr, n, m);

    cout << minn << " ";

    return 1;
}