#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//bfs traversal
void bfsOfGraph(int v, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(v,0);

    for(int i = 0; i<=v; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                vector<int>::iterator it;

                for(it = adj[node].begin(); it!=adj[node].end(); it++)
                {
                    if(!vis[*it]){
                        vis[*it] = 1;
                        q.push(*it);
                    }
                }
            }
        }
    }

    vector<int>:: iterator i;

    for(i = bfs.begin(); i!=bfs.end(); i++){
        cout<<*i<<" ";
    }
}

int main()
{
    int v;
    cin>>v;

    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);

    bfsOfGraph(v,adj);


    return 0;
}