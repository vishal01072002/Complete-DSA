#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 2){
        return 2;
    }

    int small = factorial(n-1);
    return n*small;
}

void gotoHome(int start,int destation){
    cout<<"now "<< start << " destination " << destation << endl;
    if(start == destation){
        cout<<"Phoch gaya"<<endl;
        return;
    }

    // go 1 step ahead
    int step = start+1;
    gotoHome(step,destation);
}

void counting(int num){
    if(num == 0){
        return ;
    }

    counting(num-1);
    cout<< num << " ";
}

void backCount(int num){
    cout<< num << " ";
    if(num == 1){
        return;
    }

    backCount(num-1);
}

int main()
{
    int num = 5;
    
    cout<< "factorial of "<< num << " is "<<factorial(num)<< endl;

    gotoHome(1,10);
    cout<<endl;

    counting(10);
    cout<<endl;

    backCount(10);
    cout<<endl;
    
    return 0;
}