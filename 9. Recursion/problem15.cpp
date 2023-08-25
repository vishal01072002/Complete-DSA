#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Keypad problem 
// "23" = [ "ad" "ae" "af" "bd" "be" "bf" "cd" "ce" "cf" ]

void sovle(string arr, string output, vector<string> &ans, int s, string mapping [] ){
    if(s == arr.length()){
        if(output.length() > 0)
            ans.push_back(output);
        return;
    }

    string key = mapping[arr[s] - '0'];
    for (int i = 0; i < key.length(); i++){
        output.push_back(key[i]);
        sovle(arr,output, ans, s+1, mapping);
        output.pop_back();
    }
}

int main(){
    // base if string empty return
    string arr = "23";
    string output = "";
    vector<string> ans;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    sovle(arr, output, ans, 0 , mapping);
    cout << "keypad dials are " << endl;
    for(auto &i : ans){
        cout<< i <<" ";
    }cout<<endl;
    

    return 0;
}