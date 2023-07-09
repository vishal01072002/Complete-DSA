#include <iostream>
using namespace std;

// LEETCODE = 852. Peak Index in a Mountain Array

int lastOcc(int arr[], int size)
{

    // =========== APPROCH ==========
    // either we are on left part of mountain  arr[mid] < arr[mid+1]
    // right part
    // peak of mountain

    // if we are lie on left part so start = mid+1
    // else we are on left or peak so end = mid
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            // we are lie in left part of mountain
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
    int s1 = 7;
    int mountain[] = {1, 3, 5, 6, 7, 4, 2};

    cout << lastOcc(mountain, 7) << endl;

    return 1;
}