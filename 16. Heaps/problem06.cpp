#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// minimum cost of ropes
// given n different nodes
// cost of connect 2 nodes is sum of their length
// 


int main(){
    
    vector<int> arr = {4,3,2,6};
    int n = arr.size(); 
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto i: arr){
        pq.push(i);
    }

    // logic
    int mincost = 0;
    while(pq.size() > 1){
        // find first 2 smallest element
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a+b;
        
        // insert mereged rope
        pq.push(sum);

        mincost += sum;
    }

    cout << mincost;

    return 0;
}