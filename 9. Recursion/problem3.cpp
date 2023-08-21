#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// convert digit in to word 
string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void sayDigit(int n){
    if(n == 0){
        return ;
    }

    int digit = n%10;
    n = n/10;
    sayDigit(n);

    cout<<arr[digit]<< " ";
}



int main()
{
    int num = 5844;
    
    sayDigit(num);
    
    
    return 0;
}