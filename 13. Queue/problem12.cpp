#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;

// return the sum of max and min of k window in array
void printque(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q ;
    int ans;
    vector<int> arr = {2,5,-2,7,-3,-1,-2};
    int n = arr.size();

    int mini = 9999;
    int maxi = -9999;
    int k = 4;
    int minsum = 0;
    int maxsum = 0;

    // for first k window
    for(int i=0; i<k; i++){
        mini = min(arr[i],mini);
        maxi = min(arr[i],maxi);
    }
    minsum = mini;
    maxsum = maxi;

    for(int i=0; i<n; i++){
        // first find balance
        balance = balance + currPetrol[i] - nextdist[i];
        if(balance < 0){
            kami = kami + balance;
            start = i+1;
            balance = 0;
        }
    }
    
    if(kami + balance >= 0){
        return front;
    }
    else{
        return -1;
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
    // now for last
    return 0;
}