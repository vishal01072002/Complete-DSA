#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// STRIVER medium String ques 1
// Sort Characters By Frequency

int main()
{
    string s = "abcc";

    vector<pair<int, char>> v(62, {0, 0});

    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if ('a' <= ch && ch <= 'z')
        {
            v[ch - 'a'] = {++v[ch - 'a'].first, ch};
        }
        else if ('A' <= ch && ch <= 'Z')
        {
            v[ch - 'A' + 26] = {++v[ch - 'A' + 26].first, ch};
        }
        else
        {
            v[ch - '0' + 52] = {++v[ch - '0' + 52].first, ch};
        }
    }

    sort(rbegin(v), v.rend());

    for (auto &[freq, ch] : v)
    {
        cout << freq << " " << ch << " p " << endl;
    }

    for (auto &[freq, ch] : v)
    {
        if (freq)
            cout << freq << ch;
        while (freq)
        {
            ans += ch;
            freq--;
        }
    }
    cout << endl
         << ans;

    return 0;
}