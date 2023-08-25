#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// subsets - return powerset of given array
// [1,2,3] = [ [], [1], [2], [3], [1,2], [2,3], [1,3], [1,2,3]]

void solve(int arr[], vector<int> output, vector<vector<int>> &ans, int s,int e){
    if(s == e){
        ans.push_back(output);
        return;
    }

    // exclusive
    solve(arr,output, ans, s+1, e);

    // inclusive
    output.push_back(arr[s]);
    solve(arr,output,ans,s+1,e);
}

int main(){
    int size = 3;
    int arr[3] = {1,2,3};
    vector<int> output;
    vector<vector<int>> ans;
    solve(arr, output, ans, 0,size);
    cout << "subsets are " << endl;
    for(auto &i : ans){
        for(auto &j : i){
            cout<< j <<" ";
        }
        cout<<endl;
    }

    return 0;
}