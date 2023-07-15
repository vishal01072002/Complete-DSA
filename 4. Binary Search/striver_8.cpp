#include <iostream>
using namespace std;

// STRIVER easy binary search ques 10
// Find Minimum in Rotated Sorted Array

// STRIVER easy binary search ques 11
// Find out how many times has an array is rotated

// =========== Optimal APPROCH ==========
// find pivote

int minnn(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int first = arr[0];

    if (arr[start] < arr[end])
    {
        return arr[start];
    }
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (first <= arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return arr[mid];
}

int rotation(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int first = arr[0];

    if (arr[start] < arr[end])
    {
        return 0;
    }
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (first <= arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return mid;
}

int main()
{
    int size = 7;
    int target = 3;
    // int arr[] = {4,5,6,6,7,0,1,2,4,4};
    int arr[] = {2, 2, 2, 3, 2, 2, 2};

    int minn = minnn(arr, size);
    int ans = rotation(arr, size);
    
    cout << minn << " " << ans;

    return 1;
}