#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // LEETCODE search in sorted rotated array


    // =========== Optomal Approch ============
    // only one pair exist where arr[i] > arr[i+1]

    int size = 6;
    // int nums[] = {2, 0, 1, 2, 1, 2, 0, 1, 0, 2, 0, 1};
    int nums[] = {4,5,6,7,1,2};

    int i = 0, pair = 0, k = size - 1;

    while(i<size){
        if(nums[i] > nums[(i+1)%size]){
            pair++;
            if(pair > 1){
                cout<<"not";
                return 0;
            }
        }
        i++;
    }


    cout<<"yes";
    return 1;
}