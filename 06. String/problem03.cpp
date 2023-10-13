#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// 1910. Remove All Occurrences of a Substring


void removeOccurrences(string &str, string part){
    while(str.length() != 0 && str.find(part) < str.length()){
            str.erase(str.find(part),part.length());
        }
}

int main(){
    
    string str = "daabcbaabcbc";
    string part = "abc";
    int n = str.size();

    // step 2 reverse whole string
    cout<<str<<endl;
    removeOccurrences(str,part);
    cout<<str<<endl;
    
    return 0;
}