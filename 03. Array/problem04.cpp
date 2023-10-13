#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// reverse alternate algorithms

void reverseAlt(int arr[], int size)
{
    // OR    for (int i = 0; i+1 < size; i+=2)
    for (int i = 0; i < (size - 1); i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}

int main()
{
    //  Reverse alternate in an array

    int size;
    cout << "enter size of array ";
    cin >> size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    reverseAlt(arr, size);
    printArr(arr, size);
    return 0;
}