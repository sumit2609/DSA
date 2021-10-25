#include<bits/stdc++.h>
using namespace std;

void primsAlgo(int n, vector<vector<pair<int,int>>> adj[]){
    int key[n];
    bool mst[n];
    int parent[n];

    for(int i = 0; i<n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    //priority queue contains key of i and index i{key[i],i}

    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;
        for(auto it: adj[u]){
            int v = it.first;
            int weight = it.second;

            if(mst[v] == false && weight<key[v]){
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v],v});
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

    primsAlgo(n,adj);
    return 0;
}