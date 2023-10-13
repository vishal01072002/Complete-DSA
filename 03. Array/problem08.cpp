#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //  LEETCODE = 442. Find All Duplicates in an Array

    // Given a non-empty array of integers nums, every element appears once
    // except for one. Find that duplicate value

    // ======= 1st Approch ========
    // sort array and check if 2 consicutive are same or not
    // eg. [1,2,2,3]  ==> a[1] == a[2] so ans is 2

    // ======= 2nd Approch ========

    int size = 8;
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    // int nums[] = {1,2};
    vector<int> ans;

    /*
    map<int, int> mp;

    for(auto &item:nums){
        mp[item]++;
    }

    for(auto item:mp){
        if(item.second > 1){
            ans.push_back(item.first);
        }
    }

    */

    // ==== Optomal Approch ====
    // Scan every element in array.
    // Negate the value at index of ((absolute value of scanned element) - 1)).
    // Now check if the value a the index is +ve or not.
    // If positive its a duplicate element .

    // ============== explaination ================
    // to check number(element) is duplicate or not we -(negative) value at the index of that (element-1) coz it has 1 to N (range integers)
    // eg [4,3,4,1]   1st is 4 so arry  [4,3,4,-1];

    // if any element is found +(positive) after multiply by -1 that means this index is occur 2nd time

    for (int i = 0; i < size; i++)
    {
        int element = abs(nums[i]);
        
        // make that value negative
        nums[element - 1] *= -1;
        if (nums[element - 1] > 0)
        {
            ans.push_back(element);
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 1;
}