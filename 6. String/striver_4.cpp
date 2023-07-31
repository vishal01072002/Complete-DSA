#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// STRIVER easy String ques 4

int main(){

        // find the longest common prefix string amongst an array of strings.
        vector<string> s = {"flower","flow","flight","as"} ;


        sort(s.begin(),s.end());
        for(auto &i:s){
            cout<<i;
        }

        string ans = "";
        int n = s.size();
        sort(s.begin(),s.end());
        string first = s[0];
        string last = s[n-1];

        for(int i=0; i<first.size(); i++){
            if(first[i] == last[i])
                ans += first[i];
            else
                break;
        }
        cout<< ans;
        
    return 0;
}