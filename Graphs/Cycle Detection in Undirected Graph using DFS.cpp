#include<bits/stdc++.h>
using namespace std;

bool cycleDFS(int node, vector<int> &vis, vector<int> adj[], int parent){
    for(auto it : adj[node]){
        if(!vis[it]){
            vis[it] = 1;
            if(cycleDFS(*it,vis,adj,node))
                return true;
        }else if(it!=parent){
            return true;
        }
    }
    return false;
}

bool dfs(int v, vector<int> adj[]){
    vector<int> vis(v+1,0);

    for(int i = 1; i<=v; i++){
        if(!vis[i]){
            if(cycleDFS(i,vis,adj[],-1))
                return true;
        }
    }
    return false;
}

int main(){
    return 0;
}