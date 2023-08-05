#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// rotate matrix by 90 deg
// 1 2 3                1 4 7    7 4 1
// 4 5 6        ==>     2 5 8    8 5 2
// 7 8 9                3 6 9    9 6 3
int main()
{
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int row = 4;
    int col = 4;

    // approch
    // transpose of matrix and then reverse all rows
    // column wise print

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    // transpose of matrix
    for (int i = 0; i < row; i++){
        for(int j=0; j<i; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // reverse all rows
    for (int i = 0; i < row; i++){
        int end = col-1;
        int j=0;
        while (j <= end)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][end];
            arr[i][end] = temp;
            j++,end--;
        }
        
    }
    
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}