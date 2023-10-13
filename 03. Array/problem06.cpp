#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //  LEETCODE = 1207. Unique Number Of Occurrences

    // every element in array have unique no. of occurance or not

    int size = 10;
    //int arr[] = {1, 4, -200, 4, 5, -200, 1, 1, -200, -200};
    int arr[] = {1, 4, -200, 4, 5, -200, 1, 1, 5, -200};

    // first approach
    int tempArr[2001] = {0};

    for (auto &item : arr)
    {
        tempArr[item + 1000]++;
    }

    // sort
    sort(tempArr, tempArr + 2001);

    for (int i = 0; i < 2001 - 1; i++)
    {
        // agar first value small nii  hai second se
        if (tempArr[i] != 0 && !(tempArr[i] < tempArr[i + 1]))
        {
            cout << "0";
            return 0;
        }
    }

    cout << "1";
    return 1;

    // ======== second approch =========

    /*
    map<int, int> mp; // initial value of map is zero
    unordered_set<int> st;

    // make set with number and their occurnce
    // save each occurence in set
    // set not contain duplicate element
    // so if any 2 occrence wii be same it not store it again
    // and then we check if length of map and length of set is same means true 

    for (auto &item : arr)
    {
        mp[item]++;
    }

    for(auto item :mp){
        // cout<<item.second;
        st.insert(item.second);
    }

    cout<<(mp.size() == st.size());
    return 1;
    */
}