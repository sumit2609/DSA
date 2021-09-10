#include<bits/stdc++.h>

int parent[100000];
int rank[100000];

void makeSet(){
    for(int i = 0; i<100000; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

void findParent(int node){
    if(node == parent[node]){
        return node;
    }
    //path compression
    return parent[node] = findParent(parent[node]);
}

void Union(int u,int v){
    u = findParent(u);
    v = findParent(v);

    if(rank[v]<rank[u]){
        parent[v] = u;
    }else if(rank[u]<rank[v]){
        parent[u] = v;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}