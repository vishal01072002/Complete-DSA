#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// 567. Parmutation in string

bool compare(int a[], int b[])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

bool parmutation(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    if (len1 > len2){
        return 0;
    }

    int arr1[26] = {0};
    int arr2[26] = {0};

    // store part
    for (int i = 0; i < len1; i++){
        arr1[str1[i] - 'a']++;
    }

    // for first window
    int i = 0;

    cout << len1 << i;
    while (i < len1){
        arr2[str2[i] - 'a']++;
        i++;
    }

    if (compare(arr1, arr2)){
        return 1;
    }

    // for rest elements
    while (i < len2){
        arr2[str2[i - len1] - 'a']--;
        arr2[str2[i] - 'a']++;
        if (compare(arr1, arr2)){
            return 1;
        }
        i++;
    }
    return 0;
}

int main()
{

    string str = "daiebao";
    string part = "ab";
    int n = str.size();

    cout << str << endl;
    cout << parmutation(part, str);
    cout << str << endl;

    return 0;
}