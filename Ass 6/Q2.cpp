#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* head = NULL;

void insertEnd(int x){
    Node* temp = new Node(x);
    if(!head){
        head = temp;
        temp->next = head;
        return;
    }
    Node* curr = head;
    while(curr->next != head) curr = curr->next;
    curr->next = temp;
    temp->next = head;
}

void display(){
    if(!head){ cout<<"List Empty\n"; return; }
    Node* curr = head;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr != head);
    cout<<head->data;
    cout<<"\n";
}

int main(){
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    return 0;
}
