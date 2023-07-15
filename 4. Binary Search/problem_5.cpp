#include <iostream>
using namespace std;

// search element in sorted Array (not duplicate value)

// =========== Optimal APPROCH ==========
// find pivote and apply binary search for both part

int pivote(int arr[], int size)
{

    int start = 0;
    int end = size - 1;
    int first = arr[0];

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

int binarySearch(int arr[], int start, int end, int target)
{

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}


// optimal search without pivote
int rotatedSearch(int arr[], int end, int target)
{
    int start = 0;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if(target == arr[mid]){
            return mid;
        }

        // first check for sorted then check for target
        if(arr[start] <= arr[mid]){ //left part sorted check
            if(arr[start] <= target && target <= arr[mid]){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        else{ // right part sorted 
            if(arr[mid] <= target && target <= arr[end]){
                start = mid;
            } 
            else{
                end = mid - 1;
            }
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}



int main()
{
    int size = 3;
    int target = 1;
    int arr[] = {5, 1,2};
    // int arr[] = {7,8,9, 1,2,3,4,5,6};

    cout <<"ans "<< rotatedSearch(arr, size - 1, target)<<endl;
    int mid = pivote(arr, size);
    int ans;
    if(arr[mid] <= target && target <= arr[size-1]){
        ans = binarySearch(arr, mid, size - 1, target);
    }
    else{
        ans = binarySearch(arr, 0, mid - 1, target);
    }

    if (ans == -1 )
        cout<< -1;
    else
        cout<<mid<<" mid "<<endl;

    return 1;
}