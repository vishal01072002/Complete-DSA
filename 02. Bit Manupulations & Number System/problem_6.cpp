#include <iostream>
#include <math.h>
#include <bits.h>
using namespace std;

int main()
{

    // LEETCODE = 7. Reverse Integer
    // Reverse an integer , if its out of range then return 0

    long int n;
    cout << "enter number ";
    cin >> n;

    int ans = 0;
    while (n != 0)
    {
        int rem = n % 10;
        if (ans <= (INT_MAX / 10))
            ans = ans * 10 + rem;
        else{
            ans = 0;
            break;
        }
        n /= 10;
    }

    cout << ans;
    return 0;
}