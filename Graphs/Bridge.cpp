#include<bits/stdc++.h>

using namespace std;

// low[] :- lowest insertion time among all the adjacent
// tin[] :- time of insertion

void dfs(int node, int parent,int timer, vector<int> &vis, vector<int> &tin, vector<int> &low,vector<vector<int>> &adj){
    vis[node] = 1;
    low[node] = tin[node] = timer++;

    for(auto it : adj[node]){
        if(it == parent)
            continue;

        if(!vis[it]){
            dfs(it,node,timer,vis,tin,low,adj);
            low[node] = min(low[node],tin[it]);
            //Is there a bridge condition
            if(low[it]>tin[node]){
                cout<<node<<"-"<<it<<endl;
            }
        }else{
            low[node] = min(low[node],tin[it]);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n,0);
    vector<int> tin(n,-1);
    vector<int> low(n,-1);
    int timer = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i])
            dfs(i,-1,timer,vis,tin,low,adj);
    }

    return 0;
}