#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL;}
};

Node* reverseK(Node* head, int k){
    Node* curr = head;
    Node* prev = NULL;
    Node* nextn = NULL;
    int cnt = 0;
    Node* temp = head;
    int c=0;
    while(temp && c<k){ temp=temp->next; c++; }
    if(c<k) return head;

    cnt=0;
    while(curr && cnt<k){
        nextn = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextn;
        cnt++;
    }
    if(nextn) head->next = reverseK(nextn,k);
    return prev;
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
    head->next->next->next->next->next = new Node(6);

    int k=2;
    head = reverseK(head,k);
    display(head); // 2 1 4 3 6 5

    return 0;
}
