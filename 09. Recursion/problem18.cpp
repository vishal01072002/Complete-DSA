#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Rat in a maze
bool safe(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visit, int n){
    if( (x>=0 && x<n) && (y>=0 && y<n) && visit[x][y] == 0 && maze[x][y] == 1){
        return 1;
    }
    return 0;
}

void sovle(vector<vector<int>> &maze, vector<string> &ans, int x, int y, vector<vector<int>> &visit, int n, string paths){
    if(x == n -1 && y == n-1){
        ans.push_back(paths);
        return;
    }

    // x,y pass karke aaye ho to mark kardo
    visit[x][y] = 1;

    // Down
    if(safe(x+1,y,m,visit,n)){
        paths.push_back('D');
        sovle(maze,ans,x+1,y,visit,n,paths);
        // backtrack
        paths.pop_back();
    }

    // Left
    if(safe(x,y-1,m,visit,n)){
        paths.push_back('L');
        sovle(maze,ans,x,y-1,visit,n,paths);
        // backtrack
        paths.pop_back();
    }

    // Right
    if(safe(x,y+1,m,visit,n)){
        paths.push_back('R');
        sovle(maze,ans,x,y+1,visit,n,paths);
        // backtrack
        paths.pop_back();
    }

    // Up
    if(safe(x-1,y,m,visit,n)){
        paths.push_back('U');
        sovle(maze,ans,x-1,y,visit,n,paths);
        // backtrack
        paths.pop_back();
    }

    // unvisit that visited mark coz now we gona find new value using backtracking
    visit[x][y] = 0;
    return;
}

int main(){
    vector<vector<int>>arr ;
    vector<string> ans;
    int n=5;
    if(arr[0][0] == 0){
        return ans;
    }

    vector<vector<int>> visit(n , vector<int> (n,0));

    string paths = "";
    solve(arr,ans,0,0,visit,n,paths);
    return 0;
}