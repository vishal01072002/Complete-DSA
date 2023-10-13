#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// search in a 2D matrix where matrix is row wise and col wise sorted
int main()
{
    int arr[4][4] = {1,4,7,11,2,5,8,12,3,6,9,16,10,13,14,17};
    int row = 4;
    int col = 4;
    int target = 12;
    int rowIndx = 0;
    int colIndx = col-1;

    // start from top-right or bottom left

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    while(rowIndx < row && colIndx >= 0){
        
        if(arr[rowIndx][colIndx] == target){
            cout<<"yep";
            return 0;
        }
        else if(arr[rowIndx][colIndx] > target){
            colIndx--;
        }
        else{
            rowIndx++;
        }  
    }
    cout<<"nope";
    return 0;
}