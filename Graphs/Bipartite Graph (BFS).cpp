#include<bits/stdc++.h>
using namespace std;

bool checkBipatite(int node, vector<int> &col, vector<int> adj[]){
    queue<int> q;
    q.push(node);
    col[node] = 1;
    while(!q.empty()){
        for(auto it : adj[node]){
            if(col[it] == -1){
                col[it] = 1-col[node];
                q.push(it);
            }else if(col[it] == node){
                return false;
            }
        }
    }
    return true;
}

bool bfs(int v, vector<int> adj[]){
    vector<int> color(v+1,-1);

    for(int i = 1; i<=v; i++){
        if(!checkBipartite(i,color,adj)){
            return false;
        }
    }
    return true;
}

int main(){
    return 0;
}