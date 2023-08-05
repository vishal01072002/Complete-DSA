#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// print the array in the form of spirel
int main()
{
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int rowEnd = 4-1;
    int colEnd = 4-1;
    int rowStart = 0;
    int colStart = 0;
    int count = 0;
    int total = 4*4;
    
    // row wise print
    for (int i = 0; i <= rowEnd; i++){
        for (int j = 0; j <= colEnd; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    

    while (rowStart <= rowEnd && colStart <= colEnd){   
        // left to right
        for (int i = colStart; i <= colEnd; i++){
            cout<<arr[rowStart][i]<<" ";
            count++;
        }
        // this row completed so update this
        rowStart++;
        
        // up to down
        for (int i = rowStart; i <= rowEnd ; i++){
            cout<<arr[i][colEnd]<<" ";
            count++;
        }
        colEnd--;

        // right to left
        for (int i = colEnd; i >= colStart && count < total; i--){
            cout<<arr[rowEnd][i]<<" ";
            count++;
        }
        rowEnd--;

        // down to up
        for (int i = rowEnd; i >= rowStart && count < total; i--){
            cout<<arr[i][colStart]<<" ";
            count++;
        }
        colStart++;
    }
    
    return 0;
}