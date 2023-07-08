#include <iostream>
using namespace std;

// searching algorithm
int linearSearch(int arr[], int size)
{

    int key;
    cout << "Enter number to search ";
    cin >> key;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // linear search in array

    int size;
    cout << "enter size of array ";
    cin >> size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int ans = linearSearch(arr, size);
    if (ans == -1)
        cout << "Not Found";
    else
        cout << "found at index " << ans;
    return 0;
}