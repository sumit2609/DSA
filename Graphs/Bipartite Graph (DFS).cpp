#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int node, vector<int> &col, vector<int> adj[]){
    for(auto it : adj[node]){
        if(col[it] == -1){
            col[it] = 1-col[node];
            if(!isBipartite(it,col,adj))
                return false;
        }else if(col[it] == col[node]){
            return false;
        }
    }
    return true;
}

bool checkBipartiteDFS(int v, vector<int> adj[]){
    vector<int> color(v+1,-1);

    for(int i = 1; i<=v; i++){
        if(color[i] == -1){
            color[i] = 1;
            if(!isBipartite(i,color,adj))
                return false;
        }
    }
    return true;
}

int main(){
    return 0;
}