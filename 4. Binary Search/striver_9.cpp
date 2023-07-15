#include <iostream>
using namespace std;

// STRIVER easy binary search ques 12
// Find Single element in a Sorted Array


// =========== Optimal APPROCH ==========
// find pivote

int single(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while (start < end)
    {   
        cout<<"mid "<<mid<<endl;
        if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]){
            return mid;
        }

        if (arr[mid-1] == arr[mid] ){
        cout<<"mid1 "<<mid<<endl;

            if(mid & 1){ // mid odd
                // ( even,odd) go right
                start = mid + 1;
            }
            else{
                // (odd , even) go left
                end = mid - 2;
            }
        }
        else if(arr[mid] == arr[mid+1])
        {
        cout<<"mid2 "<<mid<<endl;
            if(mid & 1){ // mid odd
                // (odd , even) go left
                end = mid - 1;
            }
            else{
                // ( even,odd) go right
                start = mid + 2;
            }
        }
        mid = start + (end - start) / 2;
    }
    return mid;
}

int main()
{
    int size = 11;
    int arr[] = {1,1,2,2,3,4,4,7,7,8,8};
    //int arr[] = {2, 2, 2, 3, 2, 2, 2};

    int ans = single(arr, size);
    cout<<ans;
    return 1;
}