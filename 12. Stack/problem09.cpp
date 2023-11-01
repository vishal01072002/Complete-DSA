#include<iostream>
#include<stack>
using namespace std;

// Check there is redundant(useless) bracket or not in expression 
bool isClosing(char ch2){
    if( ch2 == ')') return 1; 
    return 0;
}

bool isOpen(char ch){
    if(ch == '(') return 1;
    return 0;
}

bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') return 1;
    return 0;
}

int main(){
    // string s = "(a+b-((a*d)))";
    string s = "((b-c+a/c-f))";

    stack<char> st;
    int len = s.length();
    for(int i=0; i<len; i++){
        char ch = s[i];

        if(isOpen(ch) || isOperator(ch)){
            st.push(ch);
        }
        else if(isClosing(ch)){
            char tempCh = st.top();
            if(isOpen(tempCh)){
                cout <<" redundant";
                return 1;
            }
            while(!st.empty() && st.top() != '(') st.pop();
            st.pop();
        }
    }
    cout << "Not redundant";
    return 0;
}