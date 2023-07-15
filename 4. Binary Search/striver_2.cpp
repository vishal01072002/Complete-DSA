#include <iostream>
using namespace std;

// STRIVER easy binary search ques 3 (upper bound)
// upper bound of X means value < X 
// if its X so last occurence of X

int upperBound(int arr[], int size, int key)
{

    // =========== APPROCH ==========
    // value is <= KEY it may be answer so store and move to search in right part
    // else search in left part
    int start = 0;
    int end = size - 1;
    int ans = 0;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] > key){
            ans = mid;
            // cout<<"mid "<<mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int s1 = 7;
    int mountain[] = {1, 3, 4, 6, 7};

    cout << upperBound(mountain, 5, 8) << endl;

    return 1;
}