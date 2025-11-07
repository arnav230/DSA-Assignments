#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL;}
};

bool isCircular(Node* head){
    if(!head) return true;
    Node* curr = head->next;
    while(curr && curr != head) curr = curr->next;
    return (curr == head);
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2; n2->next = n3; n3->next = n1; // Circular
    cout<<(isCircular(n1)?"Yes":"No")<<endl;

    Node* m1 = new Node(10);
    Node* m2 = new Node(20);
    m1->next = m2; m2->next = NULL; // Not Circular
    cout<<(isCircular(m1)?"Yes":"No")<<endl;
}
