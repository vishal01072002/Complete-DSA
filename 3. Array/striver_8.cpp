#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 9
// Union of Two Sorted Arrays

int main()
{
    // =========== Approch 1 ============
    // store in SET O(N logN) (coz of set) it not store duplicate
    // but take O(N) extra space
    // O((m+n)log(m+n)) time compexity to insert in map or set

    // =========== Optomal Approch ============
    // 2 pointer approch
    // i and j start from 0
    // smallest element insert in UNION but 
    // before insert check last inserted value of array is not same
    // i.e last value should be less than curent value
    // if any one array element left also insert that values

    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {2,3,4,4,5,11,12};
    int n = 10;
    int m = 7;
    int i = 0, j = 0;
    int lastInsert = INT_MIN;

    vector<int> ans;
    while (i < n && j < m){
        if (arr1[i] <= arr2[j]){
            if (lastInsert < arr1[i]){
                ans.push_back(arr1[i]);
                lastInsert = arr1[i];
            }
            i++;
        }
        else{
            if (lastInsert < arr2[j]){
                ans.push_back(arr2[j]);
                lastInsert = arr2[j];
            }
            j++;
        }
    }

    while(i<n){
        if (lastInsert < arr1[i]){
            ans.push_back(arr1[i]);
            lastInsert = arr1[i];
        }
        i++;
         
    }

    while (j<m){
        if (lastInsert < arr2[j]){
                ans.push_back(arr2[j]);
                lastInsert = arr2[j];
            }
        j++;
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << (ans[i]) << " ";
    }
    
    return 0;
}