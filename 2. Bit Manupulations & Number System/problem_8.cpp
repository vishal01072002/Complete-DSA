#include <iostream>
#include <math.h>
#include <bits.h>
using namespace std;

int main()
{
    // LEETCODE = 231. Power of Two
    // Is given number is power of two(2)

    int n;
    cout << "enter number ";
    cin >> n;

    // method 1
    for(int i=0; i<=30; i++)  {

        if(pow(2,i) == n){
            cout<<true;
            return 1;
        }
    }  
    

    // method 2
    // we know power of two have exactly one  1's bit
    // not work for negstive number
    int bit = 0;

    while(n!=0){
        if(n&1){
            bit++;
        }
        n= n>>1;
    }
    if(bit == 1){
        return 1;
    }

    // method 3
    // without pow() function
    int ans = 1;
    for(int i=1; i<=31; i++)  {

        if(ans == n){
            cout<<true;
            return 1;
        }

        if (ans < INT_MAX/2)
        ans = ans*2;
    }  

    cout << false;
    return 0;
}
