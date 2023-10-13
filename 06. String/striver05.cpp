#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// STRIVER easy String ques 5

int main(){

        // Isomorphic Strings
        // s = "egg", t = "add" true
        string s = "egg" ;
        string t = "add" ;

        char seen[128] = {};
        int l1 = s.length();
        int l2 = t.length();

        if(l1 != l2){
            return 0;
        }

        for(int i=0; i<l1; i++){
            char ch = s[i];
            if(!seen[ch]){
                // insert karne se pehla dekh lo kahi kisi or se to map nii ye
                for(auto &tVal : seen){
                    if(t[i] == tVal){
                        cout<<"false"
                        return 0;
                    }
                }
                seen[ch] = t[i];
            }
            else if(seen[ch] != t[i]){
                cout<<"false"
                return 0;
            }
        }

        cout<< "true";
        
    return 0;
}