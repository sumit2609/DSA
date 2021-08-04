#include<bits/stdc++.h>
using namespace std;

bool cycleDetectionBFS(int i, vector<int> vis, vector<int> adj[]){
    queue<pair<int,int>> q;

    vis[i] = 1;
    q.push({i,-1});

    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it,node});
            }else if(par!=it){
                return true;
            }
        }
    }
    return false;
}

bool bfs(int v, vector<int> adj[]){
    vector<int> vis(v+1,0);
    
    for(int i = 1; i<=v; i++){
        if(!vis[i]){
            if(cycleDetectionBFS(i,vis,adj)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    return 0;
}