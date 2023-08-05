#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// print in the form of wave first up-TO-down then down-To-up
int main()
{
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int row = 4;
    int col = 4;
    bool UpToDown = 1;
    
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // column wise print
    for (int i = 0; i < col; i++)
    {   
        if(UpToDown)
            for (int j = 0; j < row; j++){
                cout<<arr[j][i]<<" ";
            }
        else
            for (int j = row-1; j >= 0; j--){
                cout<<arr[j][i]<<" ";
            }
        UpToDown = !UpToDown;
    }
    
    return 0;
}