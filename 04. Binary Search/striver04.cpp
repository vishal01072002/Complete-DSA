#include <iostream>
using namespace std;

// STRIVER easy binary search ques 5 
// floor and ceil value of X
// ceil = smallest value which is >= X  ====> lower bound
// floor = greatest value which is <= X  ====> modified LB

int ceil(int arr[], int size, int key)
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
    if(ans != -1){
		return arr[ans];
	}
    return ans;
}

int floor(int arr[], int size, int key)
{

    // =========== APPROCH ==========
    // find modified lower bound
    int start = 0;
    int end = size - 1;
    int ans = size;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] <= key){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    if(ans != -1){
		return arr[ans];
	}
    return ans;
}

int main()
{
    int s1 = 7;
    int mountain[] = {1, 3, 4, 6, 7};

    cout << floor(mountain, 5, 6) << endl;
    cout << ceil(mountain, 5, 6) << endl;


    return 1;
}