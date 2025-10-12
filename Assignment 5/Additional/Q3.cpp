#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL;}
};

void removeLoop(Node* head){
    if(!head || !head->next) return;
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow != fast) return;

    slow = head;
    if(slow == fast){
        while(fast->next != slow) fast=fast->next;
    }else{
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;
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

    head->next->next->next->next->next = head->next->next; // loop
    removeLoop(head);
    display(head); // 1 2 3 4 5

    return 0;
}
