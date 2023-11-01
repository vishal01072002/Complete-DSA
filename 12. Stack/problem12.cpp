#include<iostream>
#include<stack>
#include<vector>
#include<limits>
using namespace std;

// Largest rectangular area in histogram

// bruteforce 
// for each element check how much we can expand in left & right direction
// comlexity O(N2)

vector<int> nextSmall(vector<int> arr, int n){
    // we have to store index us we push indexed in stack
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];

        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }

        // now either we have -1 or index
        if(st.top() == -1) ans[i] = n;
        else { ans[i] = st.top(); }

        st.push(i);
    }
    return ans;
}

vector<int> prevSmall(vector<int> arr, int n){
    // we have to store index us we push indexed in stack
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);

    for(int i=0; i<n; i++){
        int curr = arr[i];

        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }

        // now either we have -1 or index both valid for prev
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> heights = {2,1,5,6,3};

    int n = heights.size();
    vector<int> next(n);
    vector<int> prev(n);
    int area = INT_MIN;

    next = nextSmall(heights,n);
    prev = prevSmall(heights,n);
    
    for(int i=0; i<n; i++){
        int length = heights[i];
        int breadth = next[i] - prev[i] - 1;

        int tempArea = length * breadth;
        area = max(area,tempArea);
    }
    cout << area ;
    return 0;
}