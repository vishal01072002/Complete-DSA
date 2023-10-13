#include <iostream>
#include <bits.h>
using namespace std;

// STRIVER easy binary search ques 6 and 7
// First and Last occurrence in a sorted array
// occurence count

int firstOcc(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    int ans = -1;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int size, int key)
{

    // =========== APPROCH ==========
    // find lower bound
    int start = 0;
    int end = size - 1;
    int ans = -1;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int n = 7;
    int nums[] = {1, 3, 4, 5, 5, 5, 6, 7};
    int target = 5;

    int ans1 = firstOcc(nums, n, target);
    int ans2 = lastOcc(nums, n, target);

    if (ans1 == -1 || ans2 == -1)
    {
        return 0;
    }
    return ans2 - ans1 + 1;
    return 1;
}