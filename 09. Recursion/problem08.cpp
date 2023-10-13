#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Reverse string
bool isPalandrome(string &arr, int start, int end){
    if (start > end) // all case passed
        return true;

    if(arr[start] != arr[end]) return false;

    return isPalandrome(arr, start + 1, end - 1);
}

int main(){

    string arr = "vishal";
    int start = 0;
    int ans = isPalandrome(arr, start, arr.length() - 1);
    cout << "string is palandrome " << ans << endl;

    return 0;
}