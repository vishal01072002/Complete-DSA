#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;

// given an string , first non repeating charcter in stream
// eg :- aabc  ==> a#bb
// eg :- zzc  ==> a#c
// use map for store occurence

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
    int arr[26] = {0};
    string ans = "";
    string s = "aancdndc";

    int n = s.length();


    for(int i=0; i<n; i++){
        char ch = s[i];

        // update count and push in stack
        arr[ch - 'a']++;
        q.push(ch);
        
        while(!q.empty() ){
            if(arr[q.front() - 'a'] > 1 ){
                // repeating character
                q.pop();
            }
            else{
                // non repeating character
                ans += q.front();
                break;
            }
        }

        // if queue is empty means non repeating charachter is not found use #
        if(q.empty()){
            ans += '#';
        }
    }    
    cout << ans << " ";
    
    return 0;
}