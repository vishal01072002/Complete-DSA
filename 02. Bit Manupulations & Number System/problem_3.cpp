#include<iostream>
#include<math.h>
using namespace std;


int main(){

    // DECIMAL   TO   BINARY 

    int n;
    cout<< "enter number ";
    cin>>n;
    long long int ans = 0;
    int power = 0;
    while (n!=0)
    {
       int bit = n&1;
       ans = bit* pow(10,power) + ans;
       power++;
       n = n>>1; 
    }
    cout<<ans;
    return 0;
}