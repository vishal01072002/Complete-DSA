#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// check valid palindrome

bool valid(char ch){
    if(ch >= 'a' && ch <= 'z') return 1;
    if(ch >= 'A' && ch <= 'Z') return 1;
    if(ch >= '0' && ch <= '9') return 1;
    return 0;
    
}

bool palandrome(string str){
    int s = 0;
    int e = str.size()-1;

    while(s<=e){
        char first = str[s];
        char last = str[e];
        //cout<<tolower(first);

        if(!valid(first)){
            s++;
        }
        else if(!valid(last)){
            e--;
        }
        else{
            if(tolower(first) != tolower(last)){
                return 0;
            }
            s++;
            e--;
        }
    }
    return 1;
}

int main(){
    
    string str = "c1 O$d@eeD o1c";
    
    cout<<palandrome(str);
    
    // string s = "star";
    // s[1] = '/0';
    // cout<<s; 
    return 0;
}