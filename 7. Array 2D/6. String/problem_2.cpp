#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// reverse word in string 2


// ========= Approch ==========
// e.g                          --  my name is vishal
// first reverse all word       --  ym eman si lahsiv
// then reverse whole string    --  vishal is name my


void reverseString(string &str, int start, int end){
    cout<<start<<" "<<end<<endl;
    while(start <= end){
        swap(str[start],str[end]);
        start++;
        end--;
    }
}

int main(){
    
    string str = "my name is vishal";
    int n = str.size();

    // step 1 reverse all word

    int start = 0;
    int end = 0;
    while(end<n){
        if(str[end] == ' '){
            reverseString(str,start,end-1);
            start = end+1;
        }
        if(end == n-1) reverseString(str,start,end);
        end++;
    }

    // step 2 reverse whole string
    cout<<str<<endl;
    reverseString(str,0,n-1);
    cout<<str<<endl;
    
    
    return 0;
}