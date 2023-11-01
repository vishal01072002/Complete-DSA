#include<iostream>
#include<stack>
using namespace std;

// Valid paranthesis problem
bool match(char ch1, char ch2){
    if(ch1 == '(' && ch2 == ')') return 1;
    if(ch1 == '[' && ch2 == ']') return 1;
    if(ch1 == '{' && ch2 == '}') return 1;
    return 0;
}

int main(){
    string s = "(({}[][{}]))[";

    stack<char> st;
    int len = s.length();
    for(int i=0; i<len; i++){
        char ch = s[i];

        // if opening bracket then push
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(st.empty()) return 0;
            bool valid = match(st.top(),ch);
            if(!valid){
                cout << "Not Match" << endl;
                return 0;
            }
            // if matched then pop that bracket
            st.pop();
        }
    }

    // at last if stack is empty means all bracket are matched
    if(st.empty()){
        cout << "Matched" << endl;
        return 1;
    }
    cout<< "Nope";
    return 0;
}