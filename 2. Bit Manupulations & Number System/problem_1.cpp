#include<iostream>
using namespace std;

int main(){

    // LEETCODE = 1281. Subtract the Product and Sum of Digits of an Integer

    int n;
    cout<< "enter number ";
    cin>>n;

    int sum=0 , product = 1;

    while (n>0)
    {
        int digit = n%10;
        sum += digit;
        product *= digit;

        n /= 10;
    }

    cout<<product-sum;
    
    return 0;
}