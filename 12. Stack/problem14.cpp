#include<iostream>
#include<stack>
#include<vector>
#include<limits>
using namespace std;

// Max retangle area in binary matrix with all 1's 
// comlexity O(N*M)

vector<int> nextSmall(int* arr, int n){
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

vector<int> prevSmall(int* arr, int n){
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

int largeAreaHistogram(int* arr, int n){
    vector<int> next(n);
    vector<int> prev(n);
    int area = INT_MIN;

    next = nextSmall(arr,n);
    prev = prevSmall(arr,n);
    
    for(int i=0; i<n; i++){
        int length = arr[i];
        int breadth = next[i] - prev[i] - 1;

        int tempArea = length * breadth;
        area = max(area,tempArea);
    }
    return area ;
}

int main(){
    int M[4][4] = {{0,1,1,0},
                   {1,1,1,1},
                   {1,1,1,1},
                   {1,1,0,0}};

    int n = 4, m = 4;

    // first row area
    int area = largeAreaHistogram(M[0],m);

    // continue for rest all below rows
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){

            // update row by adding above row values
            // NOTE -- if base of curr row is 0 set sum 0 for that bar
            if(M[i][j] == 0){
                M[i][j] = 0;
            }
            else{
                M[i][j] = M[i][j] + M[i-1][j];
            }
        }
        int tempArea = largeAreaHistogram(M[i],m);
        area = max(area,tempArea);
    }

    cout<< area;
    return 0;
}