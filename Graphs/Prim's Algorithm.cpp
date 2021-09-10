#include<bits/stdc++.h>
using namespace std;

void primsAlgo(int n, vector<vector<pair<int,int>>> &adj[n]){
    int key[n];
    bool mst[n];
    int parent[n];

    for(int i = 0; i<n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    // mst[0] = false;

    //As we are having N-1 edges therefore we will iterate for N-1 edges
    for(int count = 0; count<n-1; count++){

        int mini=INT_MAX,u;
        for(int i = 0; i<n; i++){
            if(mst[i] == false && key[i]<mini){
                mini = key[i];
                u = i;
            }  
        }

        mst[u] = true;

        for(auto it: adj[u]){
            int v = it.first;
            int weight = it.second;
            if(mst[v]==false && weight<key[v]){
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj[n];

    int a,b,wt;

    for(int i = 0; i<m; i++){
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }

    primsAlgo(int n, adj);

    return 0;
}