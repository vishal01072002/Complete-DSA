#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// linear search in array
int linearSearch (int arr[], int size, int key){
    if(size == 0){
        return -1;
    }

    if(arr[0] == key){
        return 1;
    }

    return linearSearch(arr+1, size-1, key);
}


int main()
{
    int size = 8;
    int key = 77;
    int arr[size] = {1,5,35,57,7,45,6,3};
    
    int index = linearSearch(arr,size,key);
    cout<< "Is "<< key << " present in array " << index << endl;
    
    return 0;
}