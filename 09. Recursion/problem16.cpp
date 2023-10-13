#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// permutation of string
// "abc" = [ "abc" "acb" "bac" "bca" "cab" "cba"]

void solve(string arr,  vector<string> &ans, int start ){
    if(start >= arr.length()){
        ans.push_back(arr);
        return;
    }

    for (int i = start; i < arr.length(); i++){
        swap(arr[i],arr[start]);
        solve(arr, ans, start+1);
        swap(arr[i],arr[start]);
    }
}

int main(){
    // base if string empty return
    string arr = "abc";
    vector<string> ans;
    solve(arr, ans, 0 );
    cout << "permutations are " << endl;
    for(auto &i : ans){
        cout<< i <<" ";
    }cout<<endl;
    

    return 0;
}