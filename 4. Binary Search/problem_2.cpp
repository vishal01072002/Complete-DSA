#include <iostream>
using namespace std;

// CODE STUDIO = first and last occurence in an sorted array of an element

int firstOcc(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (key == arr[mid])
        {
            // we found element but
            // we dont know its first occurence or not
            // so we again search in left part
            ans = mid;
            end = mid - 1;
        }

        else if (key < arr[mid])
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (key == arr[mid])
        {
            // we found element but
            // we dont know its last occurence or not
            // so we again search in right part
            ans = mid;
            start = mid + 1;
        }

        else if (key < arr[mid])
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int s1 = 7;
    int odd[] = {1, 3, 5, 5, 5, 6, 7};
    int s2 = 11;
    int even[] = {1, 3, 4, 5, 5, 6, 7, 7, 7, 8, 9};

    cout << firstOcc(odd, 7, 5) << " " << lastOcc(odd, 7, 5) << endl;
    cout << firstOcc(even, 11, 7) << " " << lastOcc(even, 11, 7);
    return 1;
}