#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node,vector<int> &vis,vector<int> adj[], vector<int> &dfsTraversal)
{
    dfsTraversal.push_back(node);
    vis[node] = 1;

    vector<int>::iterator it;
    for(it = adj[node].begin(); it!=adj[node].end(); it++){
        if(!vis[*it]){
            dfs(*it,vis,adj,dfsTraversal);
        }
    }
}

void dfsOfGraph(int v, vector<int> adj[])
{
    vector <int> dfsTraversal;
    vector <int> vis(v+1,0);

    for(int i = 1; i<=v; i++){
        if(!vis[i]){
            dfs(i,vis,adj,dfsTraversal);
        }
    }
    
    vector<int>::iterator i;
    for(i = dfsTraversal.begin(); i!=dfsTraversal.end(); i++)
    {
        cout<<*i<<" ";
    }
}


int main()
{
    int v;
    cin>>v;

    vector<int> adj[v+1];
    addEdge(adj,1,2);
    addEdge(adj,2,4);
    addEdge(adj,4,6);
    addEdge(adj,6,7);
    addEdge(adj,7,2);
    addEdge(adj,3,5);

    dfsOfGraph(v,adj);


    return 0;
}