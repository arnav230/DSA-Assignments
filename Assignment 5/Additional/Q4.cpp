#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL;}
};

Node* rotateLeft(Node* head, int k){
    if(!head || !head->next || k==0) return head;
    Node* curr = head;
    int n=1;
    while(curr->next){ curr = curr->next; n++; }
    k = k % n;
    if(k==0) return head;

    curr->next = head;
    Node* newTail = head;
    for(int i=1;i<k;i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

void display(Node* head){
    while(head){ cout<<head->data<<" "; head=head->next;}
    cout<<"\n";
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k=2;
    head = rotateLeft(head,k);
    display(head); // 3 4 5 1 2

    return 0;
}
