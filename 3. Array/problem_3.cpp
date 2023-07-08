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

// reverse algorithms
void reverse1(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void reverse2(int arr[], int size)
{
    for (int i = 0; i <= (size-1)/2; i++)
    {
        swap(arr[i],arr[size-1-i]);
    }
    
}


int main()
{
    //  Reverse an array

    int size;
    cout << "enter size of array ";
    cin >> size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    reverse1(arr, size);
    printArr(arr,size);
    
    reverse2(arr, size);
    printArr(arr,size);
    return 0;
}