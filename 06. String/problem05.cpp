#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// 1047. Remove All Adjacent Duplicates In String

// can be solve using stack
string removeAdjcent(string s){
    int len = s.length();
    string ans = "";
    ans.push_back(s[0]);
    int ansIndx = 0;

    int i=1;
    while(i < len)
    {
        if(ansIndx != -1 && ans[ansIndx] == s[i]){
            ans.pop_back();
            ansIndx--;
        }
        else{
            ans.push_back(s[i]);
            ansIndx++;
        }
        i++;
    }
    return ans;
}

int main(){
    
    string str = "abbaca";
    int n = str.size();

    cout<<str<<endl;
    cout<< removeAdjcent(str);
    
    return 0;
}