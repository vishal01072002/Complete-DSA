#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// STRIVER medium binary search ques 9
// Book allocation problem

// =========== Optimal APPROCH ==========
// binary search 

int numOfStudent(vector<int>& arr, int pages)
{
    int studentCount = 1;
    int currentStudentPage = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(currentStudentPage + arr[i] <= pages){
            currentStudentPage += arr[i];
        }
        else{
            studentCount++;
            currentStudentPage = 0;
            currentStudentPage = arr[i];
        }
    } 
    return studentCount;
}

int bookAllocate(vector<int>& arr, int size ,int m)
{
    int start = *max_element(arr.begin(),arr.end());
    int end = accumulate(arr.begin(),arr.end(),0);
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int student = numOfStudent(arr,mid);
        if(student <= m){
            end = mid - 1;
        }
        else{ // (student > m)
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    int n = 4;
    int m = 2;
    // vector<int> arr = {25,46,28,49,24};
    vector<int> arr = {12,34,67,90};

    if(n<m) return -1;
    int minn = bookAllocate(arr, n,m);
    
    cout << minn << " " ;

    return 1;
}