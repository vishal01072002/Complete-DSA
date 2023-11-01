#include<iostream>
#include<stack>
using namespace std;

// Reverse an string using stack
int main(){
    string s = "vishal kumar";

    stack<char> st;
    string ans = "";
    int len = s.length();
    int i = 0;
    while(i<len){
        st.push(s[i]);
        i++;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    cout << ans << endl;
    return 0;
}