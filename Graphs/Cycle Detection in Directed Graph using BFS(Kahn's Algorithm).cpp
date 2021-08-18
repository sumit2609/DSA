#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int n, vector<vector<int>> adj[]){
    queue<int> q;
    vector<int> indegree(n,0);

    for(int i = 0; i<n; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    for(int i = 0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int cnt = 0;

    while(!q.empty()){
        int node = q.front();
        cnt++;
        q.pop();

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(cnt == n) return false;

    return true;

}

int main(){
    isCyclic()
    return 0;
}