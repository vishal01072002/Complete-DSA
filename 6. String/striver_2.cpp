#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// STRIVER easy String ques 2

// can be solve using stack
string reverseWord(string &s,int start, int st, int e){
        string ans = "";
        cout<<start<<" ";
        while(st<=e){
            ans += s[e];
            start++;
            e--;
        }
        // start is length of word 
        cout<<start<<" "<<ans<<" rev\n";
        return ans;
    }

int main(){
    
    string s = "  a hello world  ";
        // "  dlrow olleh a  "

        // use stack
        // reverse all string
        // revrse words

        reverse(s.begin(),s.end());
        
        int len = s.length();
        int ansLength = 0;
        int wordIndx1;
        int wordIndx2 = 0;
        string ans = "";

        int i=0;
        while(i<len){
            // cout<<i;
            while(s[i] == ' '){
                i++;
            }
            wordIndx1 = i;
            wordIndx2 = i;
            // spaces removed means word encounter
            while(s[i] != ' ' && i<len ){
                wordIndx2++;
                i++;
            }
            string temp = "";
            if(wordIndx1 < wordIndx2){
                temp = reverseWord(s,ansLength,wordIndx1,wordIndx2-1);
                ansLength = wordIndx2 - wordIndx1;
                ans += temp+" "; 
            }
        }
        ans.pop_back();
        cout<<endl<<ans;


    return 0;
}