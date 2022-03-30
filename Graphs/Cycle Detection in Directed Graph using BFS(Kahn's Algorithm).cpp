#include<bits/stdc++.h>
using namespace std;

//in kahn's algo for cycle detection we calculate the indgree of all the nodes and the nodes which have indegree 0 we put 
//then inside the queue, now we take a count variable , we increment the count variable for every node having indegree 0,
//at last is count variable is equal to the number of node then cycle is not present in the graph, if cycle is present count
//can never be equal to the number of nodes as the queue will become empty earlier

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
