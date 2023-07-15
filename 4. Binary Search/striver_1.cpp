#include <iostream>
using namespace std;

// STRIVER easy binary search ques 2 (lower bound)
// lower bound of X means value >= X
// if its X so first occurence of X

int lowerBound(int arr[], int size, int key)
{

    // =========== APPROCH ==========
    // value is >= KEY it may be answer so store and move to search in left part
    // else search in right part
    int start = 0;
    int end = size - 1;
    int ans = size;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] >= key){
            ans = mid;
            cout<<mid;
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

    cout << lowerBound(mountain, 5, 8) << endl;

    return 1;
}