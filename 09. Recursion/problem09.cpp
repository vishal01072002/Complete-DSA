#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Fast exponentiation a^b

int exponent(int a, int b){
    
    if(b == 0){
        return 1;
    }

    int restValue = exponent(a,b>>1);
    if(b&1){
        // odd
        return a * restValue * restValue;
    }
    else{
        return restValue * restValue;
    }
}

int main(){

    int a = 2;
    int b = 10;
    int ans = exponent(a,b);
    cout << a << "^" << b << " is " << ans << endl;

    return 0;
}