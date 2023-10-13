#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// search in a 2D matrix where each row is sorted
int main()
{
    int arr[3][4] = {1,3,5,7,10,11,16,20,23,30,34,60};
    int row = 3;
    int col = 4;
    int target = 60;
    int start = 0;
    int end = row*col -1;
    int mid = start + (end-start)/2;

    // mid % col give column index
    // mid / col give row index

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    while(start <= end){
        int rowIndx = mid / col;
        int colIndx = mid % col;
        if(arr[rowIndx][colIndx] == target){
            cout<<"yep "<<mid;
            return 0;
        }
        else if(arr[rowIndx][colIndx] < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
        
    }
    cout<<"nope";
        
    return 0;
}