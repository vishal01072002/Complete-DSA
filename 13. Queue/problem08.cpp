#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;

// circular tour
// given petrol and distance to next petrol pump
// fin from where to start for circular tour
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
    vector<int> currPetrol = {4,6,7,4};
    vector<int> nextdist = {6,5,3,5};
    int n = arr.size();

    int kami = 0;
    int balance = 0;
    int start = 0;

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