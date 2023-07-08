#include <iostream>
using namespace std;

// BINARY SEARCH ALGORITHM

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    // int mid = (start + end) / 2;
    // int this above if start and end is large value and sum of these is out of int range so === we add and subtract (start/2)
    // then it will be start + (end - start)/2

    int mid = start + (end - start)/2;

    while (start <= end)
    {
        if (key == arr[mid])
        {
            return mid;
        }

        if (key < arr[mid])
        {
            // left part
            end = mid - 1;
        }
        else
        {
            // right part
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }
    return -1;
}

int main()
{
    int s1 = 9;
    int odd[] = {1, 3, 5, 8, 9, 10, 33, 45, 69};
    int s2 = 10;
    int even[] = {13, 25, 31, 33, 45, 49, 52, 58, 63, 69};

    cout<<binarySearch(odd,9,11);
    cout<<binarySearch(even,10,46);
    return 1;
}