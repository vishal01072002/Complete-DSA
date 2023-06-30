#include <iostream>
#include <math.h>
#include <bits.h>
using namespace std;

int main()
{
    // LEETCODE = 1009. Complement of Base 10 Integer

    // complement of Given number

    long int n;
    cout << "enter number ";
    cin >> n;

    int ans = 0, num = n;
    int shifts = 0;

    if( n==0 ){
        return 1;
    }
    
    while (n != 0)
    {
        int bit = n&1;

        // maintain shifts
        // OR mask = (mask << 1) | 1;
        shifts = shifts << 1 ;
        shifts = shifts | 1;

        n = n>>1;
    }

    ans = (~num) & shifts;    
    cout << ans;
    return 0;
}