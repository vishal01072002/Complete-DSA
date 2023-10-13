#include <iostream>
using namespace std;

int main()
{
    //  LEETCODE = 136. Single Number
    //  CODE STUDIO = duplicate in array

    // Given a non-empty array of integers nums, every element appears once
    // except for one. Find that duplicate value

    // noted** for N size array it have N-1 integer value
    // N = 4  ==> [1,2,3,2]   ==> 4-1 = 1,2,3

    // ======= 1st Approch ========
    // sort array and check if 2 consicutive are same or not 
    // eg. [1,2,2,3]  ==> a[1] == a[2] so ans is 2

    // ==== Optomal Approch ====
    // we know XOR of same number = 0
    // we XOR the array with 1 to N-1
    // so every value be "2 times" and duplicate be "3 times"
    // in 3 value 2 will be cancel

    int size = 5;
    int nums[] = {1, 4, 3, 2, 2};

    // for vector use nums.size()
    int ans = 0;
    // XOR of N-1 values
    for (int i = 1; i < size; i++)
    {
        ans = ans ^ i;
    }

    // XOR of array values
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ nums[i];
    }

    cout << ans;
    return ans;
}