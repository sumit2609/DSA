#include<bits/stdc++.h>
using namespace std;


void dijkstraAlgorithm(int src, int n, vector<vector<pair<int,int>>> adj[]){
    vector<int> dis(n+1,INT_MAX);

    dis[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push(make_pair(0,src));

    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int di = it.second;
            if(dis[it.first]>dist+di){
                dis[it.first] = dist+di;
                pq.push(make_pair(dis[it.first],it.first));
            }
            // if(dis[it.first]>dist+dis[node]){
            //     dis[it.first] = dist+dis[node];
            //     pq.push(make_pair(dis[it.first],it.first));
            // }
        }
    }

    for(int i = 1; i<n+1; i++)
        cout<<dis[i]<<" ";

}

int main(){
    return 0;
}
