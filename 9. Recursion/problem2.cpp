#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// nth term of fibonacci series
int fibonnaci(int n){
    if(n <= 1){
        return n;
    }

    // fib(n) = fib(n-1) + fib(n-2);
    return fibonnaci(n-1) + fibonnaci(n-2);
}



int main()
{
    int num = 4;
    
    cout<< "fibonacci "<< num << " th term is "<<fibonnaci(num)<< endl;
    
    return 0;
}