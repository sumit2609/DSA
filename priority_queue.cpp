#include<bits/stdc++.h>
using namespace std;

struct person{
    int age;
    int height;
    person(int a, int b){
        age = a;
        height = b;
    }
};

struct myCmp{
    bool operator()(person const &p1, person const &p2)
    {
        return p1.height<p2.height;
    }
}

int main(){
    //max heap priority queue
    priority_queue<int> pq;

    //min heap priority queue
    priority_queue<int,vector<int>,greater<int>> pq;

    //priority queue for pairs
    priority_queue<person,vector<person>,myCmp> pq;

    //operation on priority queue
        // time Complexity O(log(n))
            pq.push();
            pq.pop();
        // time complexity of O(1)
            pq.empty();
            pq.size();
            pq.top();
    return 0;
}