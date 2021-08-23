#include<bits/stdc++.h>

using namespace std;
//cycle should not be present if we need topological sort 
void topology(int node, int vis[], stack<int> &st, vector<int> adj[]){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            topology(it,vis,st,adj);
        }
    }
    st.push(node);
}

void dfs(int v, vector<int> adj[]){
    int vis[v];
    stack<int> st;

    for(int i = 0; i<v; i++){
        if(!vis[i]){
            topology(i,vis,st,adj);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    return 0;
}