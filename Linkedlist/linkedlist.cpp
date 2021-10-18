#include<bits/stdc++.h>
using namespace std;

//structure of node using struct
struct Node{
    int data;
    struct Node *next;
};

//structure of node using class
class Node{
    public:
        int data;
        Node* next;
};

int main(){

    //Initalization for class Node
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    //Initalization for struct node
    struct Node* head = new Node();
    struct Node* second = new Node();
    struct Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return 0;
}