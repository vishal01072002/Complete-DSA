#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // seive of eratosthenes 
    // complexity N*log(log N)
    // HW segmented seive
    // count the how many prime num exist between 1 to num
    int num = 10;
    int ans = 0;
    vector<bool> v (num+1,true);
    v[0] = v[1] = 0;

    for (int i = 0; i < num; i++){
        if(v[i]){
            ans++;
            for(int j=2*i; j<num; j+=i){
                v[j] = false;
            }
        }
    }

    cout<<ans;
    
    return 0;
}