#include <iostream>
using namespace std;

// Pivote element in sorted Array

int pivote(int arr[], int size)
{

    // =========== APPROCH ==========
    // [ 7 , 8 , 9 , 1 , 2 , 3] find 1
    // either we are on left part arr[0] < arr[mid] {7 < 9}
    // so go on right part start = mid + 1;
    // else end = mid;

    int start = 0;
    int end = size - 1;
    int first = arr[0];

    int mid = start + (end - start) / 2;
    while (start < end){
        if (start <= arr[mid]){
            // we are lie in left part of mountain
            start = mid + 1;
        }
        else{
            end = mid;
        }

        mid = start + (end - start) / 2;
    }
    return mid;
}

int main()
{
    int s1 = 7;
    int arr[] = { 5, 6, 7, 8, 2};

    cout << pivote(arr, 5) << endl;

    return 1;
}