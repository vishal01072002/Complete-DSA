#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array medium Ques 12
// Rotate Image by 90 degree

int main()
{
    // =========== Approch ============
    // check every element subarray sum O(N2)

    // =========== Optomal Approch ============
    // kadans algo

    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int n = 3;

    // transpose of matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // reverse each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= (n / 2)-1; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][n - j - 1];
            arr[i][n - j - 1] = temp;
        }
    }

    // print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
