#include<iostream>
#include<math.h>
using namespace std;


int main(){

    // NEGATIVE DECIMAL   TO   BINARY 

    int n,num;
    cout<< "enter negative number ";
    cin>>num;
    n = -1*num;
    long long int ans = 0;
    int power = 0;
    int bitCount = 10;
    int addOne = 1;
    while (bitCount)
    {
       int bit = !(n&1); // 1's comliment


       // 2's complement logic
       if(addOne && !(bit)) // bit add karni hai and last bit 0 hai
       {
        bit = 1;
        addOne--;
       }
       if(addOne && (bit)) // bit add karni hai and last bit 1 hai
       {
        bit = 0;
       }


       ans = bit* pow(10,power) + ans;
       power++;
       n = n>>1; 
       bitCount--;
    }
    
    cout<<ans;

    return 0;
}