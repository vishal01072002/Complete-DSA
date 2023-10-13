#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// STRIVER easy String ques 3

int main()
{

    // largest odd number
    string num = "32489";

    int n = num.length() - 1;

    while (n >= 0)
    {
        int digit = num[n] - '0';
        if (digit & 1)
        { // odd
            cout<< num.substr(0, n + 1);
            break;
        }
        n--;
    }
    cout << " ";
    return 0;
}