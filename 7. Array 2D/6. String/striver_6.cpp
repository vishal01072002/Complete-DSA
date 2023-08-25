#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// STRIVER easy String ques 6

int main(){

        //  Strings is rotated or not
        
        string s = "abcde";
        string goal = "cdeab"   ;

        int l1 = s.length();
        int l2 = goal.length();

        if(l1 != l2) return 0;
        if(s == goal) return 1;
        
        /*
		A=abcd
		B=cdab
		
		A=A+A
		A=abcdabcd
		*/

        s = s+s;
        // if no found it return large value

        int indx = s.find(goal);
        //cout<<indx;
        if(indx == -1){
            cout<< "false";
            return 0;
        }
        cout<< "true";
        return 1;
        
    return 0;
}