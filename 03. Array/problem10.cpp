#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // CODING NINJA = Sort 0's , 1's and 2's in an array
    // LEETCODE = 75. Sort Colors

    // =========== Approch 1 ============
    // use sort function

    // =========== Approch 2 ============
    // store the count of 0 or 1

    // =========== Optomal Approch ============
    // two pointer approach

    // i,j=0  , k=n-1
    // j can have 3 value
    // j=0  swap with i and i++ & j++ (coz 0 in right place so j++)
    // j=1 means increase j++
    // j=2 swap with k and k--
    // only update value when it swap with right number and
    // and j update when it have 1's only

    // till j<=k  means   j on first 2's and  k on last 1's

    int size = 6;
    // int nums[] = {2, 0, 1, 2, 1, 2, 0, 1, 0, 2, 0, 1};
    int nums[] = {2, 0, 2, 1, 1, 0};

    int i = 0, j = 0, k = size - 1;

    while (j <= k)
    {
        if (nums[j] == 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else if (nums[j] == 2)
        {
            swap(nums[j], nums[k]);
            k--;
        }
        else // j=1
        {
            j++;
        }
    }

    for (int l = 0; l < size; l++)
    {
        cout << nums[l] << " ";
    }
    cout << endl;

    return 1;
}