#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Reverse string
void reverseStr(char arr[], int start, int end){
    if (start > end)
        return;

    swap(arr[start], arr[end]);
    reverseStr(arr, start + 1, end - 1);
}

int main(){
    int size = 7;
    char arr[size] = {'v','i','s','h','a','l'};
    char arr[6] = "vishal";
    int start = 0;
    cout << "before Reverse string is " << arr << endl;
    reverseStr(arr, start, size - 1);
    cout << "Reverse string is " << arr << endl;

    return 0;
}