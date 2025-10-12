#include<bits/stdc++.h>
using namespace std;

struct DNode{
    int data;
    DNode* next;
    DNode* prev;
    DNode(int x){ data=x; next=prev=NULL;}
};

struct CNode{
    int data;
    CNode* next;
    CNode(int x){ data=x; next=NULL;}
};

int sizeDLL(DNode* head){
    int cnt=0;
    DNode* curr = head;
    while(curr){
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

int sizeCLL(CNode* head){
    if(!head) return 0;
    int cnt=1;
    CNode* curr = head->next;
    while(curr != head){
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

int main(){
    DNode* dh = new DNode(10);
    dh->next = new DNode(20);
    dh->next->prev = dh;
    dh->next->next = new DNode(30);
    dh->next->next->prev = dh->next;

    cout<<sizeDLL(dh)<<endl;

    CNode* ch = new CNode(1);
    CNode* c2 = new CNode(2);
    CNode* c3 = new CNode(3);
    ch->next = c2; c2->next = c3; c3->next = ch;

    cout<<sizeCLL(ch)<<endl;

    return 0;
}
