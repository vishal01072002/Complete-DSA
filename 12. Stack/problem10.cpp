#include<iostream>
#include<stack>
using namespace std;

// Find minimum cost to make string valid
// we can only swap '{' '}'

int main(){
    //string s = "{{}}}{";
    string s = "{}}{}}";

    stack<char> st;
    int len = s.length();

    if(len & 1) return -1;

    // remove all valid paranthesis
    for(int i=0; i<len; i++){
        char ch = s[i];

        if(ch == '{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    // now we have invalid brackets
    int open = 0;
    int close = 0;
    while(!st.empty()){
        (st.top() == '}') ? close++ : open++;
        st.pop();
    }

    cout << "Min cost " << (open+1)/2 + (close+1)/2;
    return 0;
}