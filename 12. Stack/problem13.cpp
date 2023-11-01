#include<iostream>
#include<stack>
#include<vector>
#include<limits>
using namespace std;

// Check which person is a Celebrity ?

// bruteforce 
// for each person check 
// NOTE -- not check diagonal coz every one know self
// 1. he know no One & 2. known by every one
// comlexity O(N2)

int main(){
    int persons[3][3] = {{0,1,0},
                         {0,0,0},
                         {0,1,0}};
    int n = 3;

    stack<int> st;
    for(int i=0; i<n; i++){
        st.push(i);
    }

    // check that one person that known by everyone and no know anyone
    while(st.size() > 1){
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        
        // check for celebrity
        if(persons[first][second]){
            // first Know second -- means first not celebrity
            st.push(second);
        } 
        else{
            // second Know first -- means second not celebrity
            st.push(first);
        } 
    }

    // now we have only one person in stack
    // that ** MAY BE CELEBRITY ** check for calidation
    int currPerson = st.top();

    // check for he dont Know anyone
    for(int i=0; i<n; i++){
        if(currPerson != i && (persons[currPerson][i])){
            // if curr person know anyone then he is not celebrity
            return -1;
        }
    }  

    // check for he is Known by everyone
    for(int i=0; i<n; i++){
        if(currPerson != i && !(persons[i][currPerson])){
            // if curr person is not known by atleast anyone then he is not celebrity
            return -1;
        }
    }  
    
    cout << currPerson ;
    return 0;
}