#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Intersection of 2 sorted array

    // =========== Optomal Approch ============
    // two pointer approach
    // if(arr1[i] == arr2[i]) = i++,j++ and store that common value
    // if(arr1[i] < arr2[i]) = i++
    // if(arr1[i] > arr2[i]) = j++

    int size1 = 7, size2 = 6;
    int nums1[] = {1,1,2,3,4,4,7};
    int nums2[] = {1,2,4,4,5,6};

    vector<int> ans;

    int i=0,j=0;

    while(i<size1 && j<size2){
        if(nums1[i] == nums2[j]){
            ans.push_back(nums1[i]);
            i++;j++;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }    
    
    for(int l=0; l<ans.size(); l++){
        cout<<ans[l]<<" ";
    }

    return 1;
}