#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    // BINARY TO DECIMAL

    long int n;
    cout << "enter binary number ";
    cin >> n;
    long int decimal = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n % 10;
        if (bit)
            decimal += pow(2, i);
        i++;
        n /= 10;
    }
    cout << decimal;
    return 0;
}