#include<bits/stdc++.h>
using namespace std;

struct Node{
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p){ coeff=c; pow=p; next=NULL;}
};

Node* addPoly(Node* a, Node* b){
    Node* head=NULL;
    Node* tail=NULL;
    while(a && b){
        Node* temp=NULL;
        if(a->pow > b->pow){ temp = new Node(a->coeff,a->pow); a=a->next; }
        else if(a->pow < b->pow){ temp = new Node(b->coeff,b->pow); b=b->next; }
        else{ temp = new Node(a->coeff+b->coeff,a->pow); a=a->next; b=b->next; }
        if(!head) head=tail=temp;
        else{ tail->next=temp; tail=temp; }
    }
    while(a){ Node* temp=new Node(a->coeff,a->pow); tail->next=temp; tail=temp; a=a->next; }
    while(b){ Node* temp=new Node(b->coeff,b->pow); tail->next=temp; tail=temp; b=b->next; }
    return head;
}

void display(Node* head){
    while(head){ cout<<"["<<head->coeff<<", "<<head->pow<<"] "; head=head->next; }
    cout<<"\n";
}

int main(){
    Node* poly1 = new Node(5,2);
    poly1->next = new Node(4,1);
    poly1->next->next = new Node(2,0);

    Node* poly2 = new Node(5,1);
    poly2->next = new Node(5,0);

    Node* res = addPoly(poly1, poly2);
    display(res); 

    return 0;
}
