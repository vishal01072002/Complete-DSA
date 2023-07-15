#include <iostream>
using namespace std;

// // STRIVER easy binary search ques 9
// search element in sorted Array (duplicate value)
// edge case [3,1,2,3,3,3,3]  so we trim the array

// =========== Optimal APPROCH ==========
// Handle edge case while finding element 

// optimal search without pivote
bool rotatedSearch(int arr[], int end, int target)
{
    int start = 0;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if(target == arr[mid]){
            return 1;
        }

        if(arr[start] == arr[mid] && arr[mid] == arr[end]){
            start++;
            end--;
            continue;
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
    return 0;
}

int main()
{
    int size = 19;
    int target = 2;
    // int arr[] = {4,5,6,6,7,0,1,2,4,4};
    // int arr[] = {2,2,2,3,2,2,2};
    int arr[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};

    cout<<"rotated "<<rotatedSearch(arr,size-1,target)<<endl;
    return 1;
}