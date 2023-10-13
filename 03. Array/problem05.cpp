#include <iostream>
using namespace std;

int main()
{
    //  LEETCODE = 136. Single Number

    // Given a non-empty array of integers nums, every element appears twice
    // except for one. Find that single one.

    int size = 5;
    int nums[] = {1, 4, 4, 5, 1};

    // for vector use nums.size()
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ nums[i];
    }

    cout << ans;
    return ans;
}