#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 7
// Move all Zeros to the end of the array (maintain order)

int main()
{
    // =========== Approch 1 ============
    // store non Zero in another array
    // and then fill zeros

    // =========== Optomal Approch ============
    // 2 pointer approch
    // i and j start from 0

    // if ( ele[j] != 1)  => swap , i++ 
    // means when j on non Zero then we swap on i++
    // else  => j++
    // means j on 0 and we have to put non zero at start (on i th position)

    //int arr[] = {0, 1, 0, 2, 0, 2, 0, 3, 6, 3};
    int arr[] = {4 ,0 ,3 ,2 ,5};
    int n = 5;
    int i = 0, j = 0;

    while (j < n)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}