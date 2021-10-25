#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
};

void push(Node** head, int key){
    Node *newNode = new Node();
    newNode->data = key;
    newNode->next = (*head);
    (*head) = newNode;
}

void printLinkedList(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    // cout<<endl;
}

void DeleteLinkedList(Node** head, int key){
    Node* temp = *head;
    Node* prev = NULL;

    //if head node contains key
    if(temp!=NULL && temp->data == key){
        *head = temp->next;
        delete temp;
    }else{
        //if head node doews't contains key
        while(temp!=NULL && temp->data!=key){
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
            return;
        
        prev->next = temp->next;
        delete temp;
    }

}

int main(){

    Node *head = NULL;

    //Insert element in tha linkedlist
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    printLinkedList(head);
    DeleteLinkedList(&head,7);
    cout<<endl;
    printLinkedList(head);
    return 0;
}

