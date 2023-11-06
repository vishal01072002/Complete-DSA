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
    int k = 4;
    vector<int> arr = {2,5,-1,7,-3,-1,-2};
    int n = arr.size();
    int ans = 0;

    deque<int> mini ;
    deque<int> maxi ;

    // for first k window
    for(int i=0; i<k; i++){

        // adding element in queue 
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        maxi.push_back(i);

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        mini.push_back(i);
    }

    // calculate answer for first k window
    cout<< arr[maxi.front()] << " " << arr[mini.front()] << endl;
    ans += arr[maxi.front()] + arr[mini.front()];

    for(int i=k; i<n; i++){
        // next window 

        // removal of element that not be in window
        while (maxi.front() <= i-k){
            maxi.pop_front();
        }
        while(mini.front() <= i-k){
            mini.pop_front();
        }

        // adding of element in queue
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        maxi.push_back(i);

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        mini.push_back(i);   

        // calculate answer for that window
        cout<< arr[maxi.front()] << " " << arr[mini.front()] << endl;
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    
    cout<< ans <<" ";
    
    return 0;
}