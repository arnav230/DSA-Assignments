#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){ val=x; next=NULL; }
};

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    a->next=b; b->next=c; c->next=d; d->next=b;

    unordered_set<Node*> s;
    Node* cur=a;
    while(cur){
        if(s.count(cur)){
            cout<<"true";
            return 0;
        }
        s.insert(cur);
        cur=cur->next;
    }
    cout<<"false";
}
