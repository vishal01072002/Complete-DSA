#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;

// given an array print first negative number in every K size window
// if not present then 0
// approach using queue to make sliding window of K size
void printque(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q ;
    int K = 2;
    vector<int> ans;
    vector<int> arr = {-8,2,3,-6,10};

    int n = arr.size();
    // first create K size window
    for(int i=0; i<K; i++){
        if(arr[i]<0){
            q.push(i);
        }
    }

    // store answer for first K size window
    if(q.size() > 0){
        ans.push_back(arr[q.front()]);
    }
    else{
        ans.push_back(0);
    }
    

    // now check for rest window
    for(int i=K; i<n; i++){
        // remove first element from window if that from prev window
        if(!q.empty() && (i - q.front() >= K)){
            // not in window so remove that
            q.pop();
        }

        // add new element
        if(arr[i] < 0){
            q.push(i);
        }

        // store answer for current window
        if(q.size() > 0){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    for(auto i: ans){
        cout<<i<<" ";
    }
    // now for last
    return 0;
}