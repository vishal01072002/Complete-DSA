#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// striver array easy Ques 11
// Count Maximum Consecutive One’s in the array

int main()
{

    // =========== Optomal Approch ============
    // we maintain last maximum 1's count if we found onother one
    // then we update max 1's count

    int arr[] = {0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1};
    int ans = -1;
    int count = 0;
    int n = 11;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 1){
            count ++;
        }
        else{
            ans = max(ans,count);
            count = 0;
        }
    }
    // for if last value is 1
    ans = max(ans,count);

    cout << ans;
    return 0;
}