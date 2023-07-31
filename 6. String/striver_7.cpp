#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// STRIVER easy String ques 7

int main()
{

    //  valid anagram

    string s = "anagram";
    string t = "nagaram";

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); i++){
        if (s[i] != t[i]){
            cout << "false";
            return 0;
        }
    }

    cout << "true";
    return 1;

}