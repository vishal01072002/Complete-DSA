#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Subsequences of string - return powerset of given array
// [abc] = [ [] [a] [b] [c] [ab] [bc] [ac] [abc]]

void sovle(string arr, string output, vector<string> &ans, int s,int e){
    if(s == e){
        if(output.length() > 0)
            ans.push_back(output);
        return;
    }

    // exclusive
    sovle(arr,output, ans, s+1, e);

    // inclusive
    output.push_back(arr[s]);
    sovle(arr,output,ans,s+1,e);
}

int main(){
    int size = 3;
    string arr = "abc";
    string output = "";
    vector<string> ans;
    sovle(arr, output, ans, 0,size);
    cout << "Subsets are " << endl;
    for(auto &i : ans){
        cout<< i <<" ";
    }

    return 0;
}