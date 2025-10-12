#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL;}
};

Node* getIntersection(Node* head1, Node* head2){
    Node* a = head1;
    Node* b = head2;
    while(a != b){
        a = a ? a->next : head2;
        b = b ? b->next : head1;
    }
    return a;
}

int main(){
    Node* n1 = new Node(1);
    n1->next = new Node(2);
    n1->next->next = new Node(3);

    Node* n2 = new Node(4);
    n2->next = new Node(5);

    Node* common = new Node(6);
    common->next = new Node(7);

    n1->next->next->next = common;
    n2->next->next = common;

    Node* inter = getIntersection(n1,n2);
    if(inter) cout<<inter->data<<endl;
    else cout<<"No Intersection\n";

    return 0;
}
