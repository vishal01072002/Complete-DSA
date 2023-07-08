#include <iostream>
using namespace std;

int main()
{

    // minimum and maximum number in array

    int size;
    cout << "enter size of array ";
    cin >> size;

    int arr[100];
    int minNum = INT_MAX;
    int maxNum = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        if (maxNum < arr[i])
            maxNum = arr[i];

        // inbuilt min , max function
        minNum = min(minNum , arr[i]);
    }

    cout << maxNum << " " << minNum;

    return 0;
}