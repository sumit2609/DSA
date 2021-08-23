#include<bits/stdc++.h>
using namespace std;

// Shortest Path in Undirected Graph with Unit Weights

void shortestPath(int src, int n,vector<int> adj[]){
    int dist[n];
    for(int i = 0; i<n; i++)
        dist[i] = INT_MAX;

    queue<int> q;
    dist[src] = 0;

    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout<<dist[i]<<" ";
    }
}

int main(){
    return 0;
}