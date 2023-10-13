#include<iostream>
using namespace std;

int main(){

    // LEETCODE = 191. Number of 1 Bits

    int n;
    cout<< "enter number ";
    cin>>n;
    int ans = 0;
    while (n!=0)
    {
       if(n&1)
       {
        ans++;
       }
       n = n >> 1;
    }

    cout<<ans;
    
    return 0;
}