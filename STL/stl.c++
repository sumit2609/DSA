#include<bits/stdc++.h>
using namespace std;

void expainPair(){
    pair <int,int> p = {1,3};

    //print 1,3
    cout<<p.first<<" "<<p.second;

    pair<int,pair<int,int>> p = {1,{3,4}};

    //print 1 4 3
    cout<<p.first<<" "<<p.second.second<<" "<<p.second.first;

    pair<int, int> arr[] = {{1,2},{2,5},{5,1}};

    //print 5
    cout<<arr[1].second;
}

//Binary search using stl

Q1. Check if X exists in sorted array or not?
A[] = {1,4,5,8,9}

bool res = binary_search(a,a+n,3);//return false
bool res = binary_search(a,a+n,4);//return true

lower_bound function:
//log(n) time complexity
//lower bound is a function that gives iterator pointing
//towards the given element and if it is not found then it will 
//point toward the immidiate next greater element

//to get the index we will substact interator to index 1 from lower_bound()

a[] = {1,4,5,6,9,9}

int ind = lower_bound(a,a+n,4)-a;//this will return 1
int ind = lower_bound(a,a+n,7)-a;//return 4
int ind = lower_bound(a,a+n,10)-a;//return 6

//lower_bound for vector
int ind = lower_bound(a.begin(),a.end(),x)-a.begin();

========================================================================================

Upper_bound function:
//log(n) time complexity
//upper bound is a function that gives the iterator pointing
//to next element of the given element and if then element is not found it 
//points to next greater element

a[] = {1,4,5,6,9,9}

int ind = upper_bound(a,a+n,4)-a;
int ind = upper_bound(a,a+n,7)-a;
int ind = upper_bound(a,a+n,10)-a;

//upper bound for vectors
int ind = upper_bound(a.begin(),a.end(),a)-a.begin();

// vector
void explainVector(){
    // an empty vector
    vector <int> v;
    
    v.push_back(1);//{1}
    v.emplace_back(2);//{1,2}

    vector<pair<int,int>> vec;
    v.push_back({1,2});
    v.emplace_back(1,2);//if vector is of pair type no need of curly braces

    //vector of size 5 with
    //everyone as 100

    vector<int> v(5,100);//[100,100,100,100,100]

    //A vector of size 5 
    //initialized with 0
    //might take garbage value
    //dependent on the vector
    
    vector<int> v(5);//{0,0,0,0,0}

    vector<int> v1(5,20);//{20,20,20,20,20}
    vector<int> v2(v1);//{20,20,20,20,20}


    //take a vector to be {10,20,30,40}
    vector<int>::iterator it = v.begin();
    // if we use v.cbegin() iterator will not move
       
    it++;
    cout<<*(it)<<" ";//prints 20

    it = it+2;// initially it is at begin
    cout<<*(it)<<" ";//prints 30

    vector <int>::iterator it = v.end();
    vector<int>::iterator it = v.rend();//this will point to 40
    vector<int>::iterator it = v.rbegin();//this will point before 10

    //both will give v[0];
    cout<<v[0]<<" "<<v.at(0);

    //to get last element of the vector
    cout<<v.back()<<" ";
    
    // ways to print the vector

    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++){
        cout<<*(it)<<" ";
    }

    for(auto it = v.begin(); it!=v.end(); it++){
        cout<<*(it)<<" ";
    }

    for(auto it : v){
        cout<<it<<" ";
    }

    // let v = {10,20,12,23}
    v.erase(v.begin())//{20,12,23}
    v.erase(v.begin()+1)//{10,12,23}

    //{10,20,12,23,35}
    v.erase(v.begin()+2,v.begin()+4);//{10,20,35}//[start,end)

    //Insert function

    vector<int> v(2,100);//{100,100}
    v.insert(v.begin(),300);//{300,100,100}
    v.insert(v.begin()+1,2,10)//{300,10,10,100,100}

    vector<int> copy(2,50);
    v.insert(v.begin(),copy.begin(),copy.end());//{50,50,300,10,10,100,100}

    //{10,20}
    cout<<v.size();//2

    //{10,20}
    v.pop_back();//{10}

    //v1->{10,20}
    //v2->{30,40}
    v.swap(v2);//v1->{30,40}, v2->{10,20}

    v.clear();//erase the entire vector

    cout<<v.empty();//true if empty
}


void explainList(){
    list<int> ls;

    ls.push_back(2);//{2}
    ls.emplace_back(4);//{2,4}

    ls.push_front(5);//{5,2,4}

    ls.emplace_front();//{2,4}

    //rest function same as vector
    //begin, end, ebegin, rend, cleat, insert, size, swap
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(1);//{1}
    dq.emplace_back(2);//{1,2}
    dq.push_front(4);//{4,1,2}
    dq.emplace_back(3);//{3,4,1,2}

    dq.pop_back();//{3,4,1}
    dq.pop_front();//{4,1}

    dq.back();//{1}
    dq.front();//{4}

    //rest functions same as vector
    //begin, end, rbegin, rend, clear, insert, size, swap
}

void explainStack(){
    stack <int> st;
    st.push(1);// {1}
    st.push(2);// {2,1}
    st.push(3);// {3,2,1}
    st.push(3);// {3,3,2,1}
    st.emplace(5);// {5,3,3,2,1}

    cout<<st.top();// print 5

    st.pop();// st look {3,3,2,1}

    cout<<st.top();// 3
    cout<<st.size();//4
    cout<<st.empty();//false
    
    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue() {
    queue<int> q;
    q.push(1);//{1}
    q.push(2);//{1,2}
    q.emplace(4);//{1,2,4}

    q.back() += 5

    cout<<q.back();//prints 9

    //0 is {1,2,9}
    cout<<q.front();//print 1

    q.pop();//{2,9}

    cout<<q.front();//print 2

    //size swap empty same as stack
}

void explainPQ(){
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(18); //{10,8,5,2}

    cout<<pq.top(); // prints 10

    pq.top(); // {8, 5, 2}

    cout<<pq.top();// prints 8

    // size swap empty function same as other

    //Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);// {5}
    pq.push(2);// {2,5}
    pq.push(8);// {2,5,8}
    pq.emplace(10);// {2,5,8,10}

    cout<<pq.top();// print 2
}

void explainSet(){
    set<int> st;   
    st.insert(1);//{1}
    st.emplace(2);//{1,2}
    st.insert(2);//{1,2}
    st.insert(4);//{1,2,4}
    st.insert(3);//{1,2,3,4}

    //Functionality of insert in vector
    //can be used also, that only increases
    // efficiency

    //begin(), end(), rbegin(), rend(), size()
    //empty() and swap() are same as those of above

    //{1,2,3,4,5}
    auto it = st.find(3);
    
    //{1,2,3,4,5}
    auto it = st.find(6);// it will point to st.end()

    //{1,4,5}
    st.erase(5);//erases 5 // takes logarithmic time

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it);// it takes constant time

    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2);// after erase {1,4,5} [first,last)

    //lower_bound() and upper_bound() function works in the same way
    //as in vector it does

    //this is synatax

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}    

void explainMultiSet(){
    //Everything is same as set
    //only stores duplicates elements also

    multiset<int>ms;
    ms.insert(1);//{1}
    ms.insert(1);//{1,1}
    ms.insert(1);//{1,1,1}

    ms.erase(1);//all 1's erased

    int cnt = ms.count(1);

    //only a single one erased
    ms.erase(ms.find(1));

    //2 1's are erased
    ms.find(ms.find(1),ms.find(1)+2);
}

void explainUnordered_set(){
    unordered_set<int> st;
    //lower_bound and upper_bound function
    //does not works, rest all functions are same
    //as above, it does not stores in any
    //particular order it has better complexity
    //than set in most cases, except some when collision happens
}

void explainMap(){

    //{key, value}
    map<int,int> mpp;
    map<int,pair<int,int>> mpp;
    map<pair<int,int>,int> mpp;

    //key value can be any thing

    mpp[1] = 2;//1 is key 2 is value
    mpp.emplace({3,1});//3 is key 1 is value
    mpp.insert({2,4});//2 is key 4 is value

    //elements in map will be in sorted order
    {
        {1,2}
        {2,4}
        {3,1}
    }

    mpp[{2,3}] = 10;

    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    //same options for using iterator
    //as we did in vector for the insert function

    cout<<mpp[1];//prints 2
    cout<<mpp[5];//prints o, since it does not exist

    auto it = mpp.find(3);//points to the position where 3 is found
    cout<<*(it).second;

    auto it = mpp.find(5);// points to the end of the map since 5 not there

    //lower_bound and upper_bound works exactly in the
    //same way as explained in the other video

    //This is the syntax
    auto it = mpp.lower_bound(key);

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    //erase,swap,size,empty, are same as above
}

void explainMultimap(){
    //everything same as map, only it can store multiple keys
    //only mpp[key] cannot be used here
    //like we want ton store {1,2} and {1,2} we will use Multimap()
}

void explainUnorderedmap(){
    //same as set and unordered_set difference
}

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second<p2.second){
        return true;
    }else if(p1.second == p2.second){
        if(p1.first>p2.second)
            return true;
    }
    return false;
}

void explainExtra(){
    sort(a,a+n);//sorts in ascending order
    sort(a,a+n,greater<int>);//sorts in descending order

    pair<int,int> a[] = {{1,2},{2,1},{4,1}};

    //sort it according to second element
    //if second element is same, then sort
    //it according to first element but in descending

    sort(a,a+n,comp);
    //{{4,1},{2,1},{1,2}};

    int num = 7;//111
    int cnt = __builtin_popcount();//this will count set bits of integer

    long long num = 165786578687;
    int cnt = __builtin_popcountll();//tis will count set bit for long long

    string s = "123";
    
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
    //123
    //132 
    //213
    //231
    //312
    //321

    //max element in a range
    int maxi = *max_element(a,a+n);
}

int main(){
    return 0;
}