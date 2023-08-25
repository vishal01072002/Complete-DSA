#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// STRIVER medium String ques 2
// roman to integer

int romToVal(char ch)
{
    if (ch == 'I')
        return 1;
    if (ch == 'V')
        return 5;
    if (ch == 'X')
        return 10;
    if (ch == 'L')
        return 50;
    if (ch == 'C')
        return 100;
    if (ch == 'D')
        return 500;
    return 1000;
    // also can use map
}

int main()
{
    string s = "XXXIVC";

    int ans = 0;
    int n = s.length() - 1;
    char prevRoman = s[n];
    for (int i = n; i >= 0; i--){
        int romval = romToVal(s[i]);
        if (romToVal(prevRoman) > romval){
            ans -= romval;
        }
        else{
            ans += romval;
        }
        prevRoman = s[i];
    }
    cout << ans;

    return 0;
}