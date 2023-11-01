#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//find next smaller element for each element

// bruteforce use 2 for loop 

int main(){
    vector<int> arr = {0,1,5,3};
    stack<int> st;

    st.push(-1);
    int n = arr.size();
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];

        while(st.top() >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(curr);
    }

    cout << "Ans array \n";
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}