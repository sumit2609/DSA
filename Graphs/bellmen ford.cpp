#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    //m = edges
    //n = vertices

    vector<node> edges;

    for(int i = 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }

    int src;
    cin>>src;

    vector<int> dist(n,INT_MAX);

    dist[src] = 0;

    for(int i = 0; i<n-1; i++){
        for(auto it: edges){
            if(dist[it.u]+it.wt<dist[it.v]){
                dist[it.v] = dist[it.u]+it.wt;
            }
        }
    }

    int fl = 0;

    for(auto it: edges){
        if(dist[it.u]+wt < dist[it.v]){
            cout<<"Negative Cycle";
            f1 = 1;
            break;
        }
    }

    if(!f1){
        for(int i = 0; i<n; i++)
            cout<<i<<" "<<dist[i]<<endl;
    }

    return 0;
}