#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, int vis[], int dfsVis[], vector<int> adj[])
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkCycle(it,vis,dfsVis,adj))
                return true;
        }else if(dfsVis[it]){
            return true;
        }
    }

    dfsVis[node] = 0;
    return false;
}

bool dfs(int v, vector<int> adj[]){
    int vis[v];
    int dfsVis[v];

    memset(vis,0,sizeof(vis));
    memset(dfsVis,0,sizeof(dfsVis));

    for(int i = 0; i<v; i++){
        if(!vis[i]){
            if(checkCycle(i,vis,dfsVis,adj))
                return true;
        }
    }
    return false;
}

int main(){
    return 0;
}