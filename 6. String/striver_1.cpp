#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// STRIVER easy String ques 1

int main()
{

    string s = "(()())(())";

    // split into non splitable paranthisis
    // like (()())(())  ==  (()()) + (())
    // then remove outer most brackets

    int paranthisisCount = 0;
    string ans = "";
    bool start = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (start)
        {
            ans.push_back(s[i]);
        }
        if (s[i] == '(')
        {
            paranthisisCount++;
            start = 1;
        }
        else
        { // ')'
            paranthisisCount--;
        }

        if (paranthisisCount == 0)
        {
            start = 0;
            ans.pop_back();
        }
    }
    cout<< ans;

    return 0;
}