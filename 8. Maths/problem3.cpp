#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// modular operation
/*
    (a+b) % m = a % m + b % m
    (a-b) % m = a % m - b % m
    (a*b) % m = a % m * b % m

    fast Exponentiation a^b 
    Complexity = O(Log b)
*/
int powers (int a,int b){
    int m = 1000000007;
    int res = 1;
    while(b>0){
        if(b&1){
            // odd
            res = (1LL * (res)%m * (a)%m)%m;
        }
        a = (1LL * (a)%m * (a)%m) %m;
        b = b>>1;
    }
    return res;
}
int main()
{
    // Gcd using euclidean algorithm
    // GCD(a,b) = GCD(a-b,b)
    // LCM(a,b) * GCD(a,b) == a*b
    int a = 2;
    int b = 20;
    int ans ;
    
    ans = powers(a,b);
    cout<<ans;
    
    return 0;
}