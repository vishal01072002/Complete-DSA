#include <iostream>
using namespace std;

// Squre root of an number

// =========== Optimal APPROCH ==========
// apply binary search in range ( 0 to N) 

int sqrRoot(int num)
{

    int start = 0;
    int end = num;
    int ans = -1;

    long long int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (mid*mid == num)
        {
            return mid;
        }
        if(mid*mid < num ){
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

float extraPrecision(int num, int precision,int tempRoot){
    double factor = 1;
    double ans = tempRoot;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        double j = ans;
        while(j*j < num){
            ans = j;
            j = j + factor;
        }   
    }
    return ans;
}
int main()
{
    int n = 8;
    int ans = sqrRoot(n);
    cout<<ans<<endl;
    cout<<extraPrecision(n,10,ans)<<endl;

    return 1;
}