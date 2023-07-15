#include <iostream>
using namespace std;

// STRIVER easy binary search ques 4 (inseting index of value)
// means lower bound

int insertIndx(int arr[], int size, int key)
{

    // =========== APPROCH ==========
    // find lower bound
    int start = 0;
    int end = size - 1;
    int ans = size;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] >= key){
            ans = mid;
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

    cout << insertIndx(mountain, 5, 5) << endl;

    return 1;
}