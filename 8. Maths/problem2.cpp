#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int GCD (int a,int b){
    if(!a) return b;
    if(!b) return a;

    while(a != b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}
int main()
{
    // Gcd using euclidean algorithm
    // GCD(a,b) = GCD(a-b,b)
    // LCM(a,b) * GCD(a,b) == a*b
    int a = 24;
    int b = 72;
    int ans ;
    
    ans = GCD(a,b);
    cout<<ans;
    
    return 0;
}