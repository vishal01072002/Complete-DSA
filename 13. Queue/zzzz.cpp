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

    vector<int> ans;
    deque<int> maxi ;

    // for first k window
    for(int i=0; i<k; i++){
        // remove small element
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.back();
        }
        maxi.push_back(i);
    }

    // calculate answer for rest k window
    for(int i=k; i<n; i++){
        ans.push_back([maxi.front()]);

        // remove element which not lie in window
        while(maxi.front() <= n-k){
            maxi.pop_front();
        }

        // add new element
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        maxi.push_back(i);
    }

    // max sum path of BT
    // left sum 
    int maxSum(node* root){
        if(root == NULL){
            return 0;
        }

        int left = maxSum(root->left);
        int right = maxSum(root->right);

        return max(left,max(right,left+right+root->data))
    }


    // next permutation
    vactor<int> temp = {2,1,5,4,3,0};

    // find break point
    int n = temp.size();
    int breakPoint = -1
    for(int i=n-1; i>0; i--){
        if(temp[i] > temp[i-1]){
            breakPoint = i;
        }
    }

    if(breakPoint == -1){
        // reverse all array
        reverse(temp.begin(),temp.end());
        return temp;
        // and return
    }

    // 2,1,5,4,3,0
    // swap with first smallest from last
    int mini = n-1;
    for(int i=n-1; i>0; i--){
        if(temp[mini] < temp[i]){
            mini = i;
        }
    }
    // 2,3,5,4,1,0
    swap(temp[breakPoint],temp[mini]);
    for(int i= n-1; i>breakPoint;i--){
        swap(temp[i],temp[]);
    }
    // reverse rest
    // 2,3,0,1,4,5
    
    return 0;
}