#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// 443. String Compression

int intToString(vector<char> &s, int ansIndx, int count)
{
    if (count < 10 && count > 1){
        s[ansIndx] = (count) + '0';
        ansIndx++;
    }
    if (count > 9){
        string temp = to_string(count);
        for (int i = 0; i < temp.length(); i++){
            s[ansIndx] = temp[i];
            ansIndx++;
        }
    }
    return ansIndx;
}

vector<char> strCompress(vector<char> &s)
{
    int len = s.size();
    int count = 1;
    char first = s[0];
    int ansIndx = 0;

    int i = 1;
    while (i < len)
    {
        if (first == s[i])
        {
            count++;
        }
        else
        {
            // new char encounter

            // store prev char
            s[ansIndx] = first;
            ansIndx++;

            // convert count in string and store

            ansIndx = intToString(s,ansIndx,count);

            // update start
            first = s[i];
            count = 1;
        }
        i++;
    }

    // for last case when string is end
    s[ansIndx] = first;
    ansIndx++;
    ansIndx = intToString(s,ansIndx,count);
    cout<<ansIndx;

    return s;
}

int main()
{

    vector<char> str = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> temp;
    int n = str.size();

    cout << endl;
    temp = strCompress(str);
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }

    // cout<< ;

    return 0;
}