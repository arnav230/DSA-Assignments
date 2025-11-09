#include<bits/stdc++.h>
using namespace std;

struct nd1{ int d; nd1 *p,*n; };   // doubly linked
struct nd2{ int d; nd2 *n; };     // circular singly

nd1 *h1=NULL,*t1=NULL;
nd2 *last2=NULL;

nd1* mk1(int v){
    nd1 *x=new nd1;
    x->d=v; x->p=x->n=NULL; return x;
}
nd2* mk2(int v){
    nd2 *x=new nd2;
    x->d=v; x->n=NULL; return x;
}

void addDL(int v){
    nd1 *x=mk1(v);
    if(h1==NULL) h1=t1=x;
    else{ t1->n=x; x->p=t1; t1=x; }
}
void addCL(int v){
    nd2 *x=mk2(v);
    if(last2==NULL){ last2=x; x->n=x; }
    else{ x->n=last2->n; last2->n=x; last2=x; }
}

void delEvenDL(){
    nd1 *t=h1;
    while(t){
        if(t->d%2==0){
            if(t==h1 && t==t1){ h1=t1=NULL; delete t; return; }
            else if(t==h1){ h1=h1->n; h1->p=NULL; nd1 *z=t; t=t->n; delete z; continue; }
            else if(t==t1){ t1=t1->p; t1->n=NULL; nd1 *z=t; t=t->n; delete z; continue; }
            else{ t->p->n=t->n; t->n->p=t->p; nd1 *z=t; t=t->n; delete z; continue; }
        }
        t=t->n;
    }
}

void delEvenCL(){
    if(last2==NULL) return;
    nd2 *t=last2->n,*pr=last2;
    int first=1;
    do{
        if(t->d%2==0){
            if(t==last2 && t==last2->n){ delete t; last2=NULL; return; }
            if(t==last2){ pr->n=t->n; last2=pr; delete t; t=pr->n; continue; }
            if(t==last2->n){ last2->n=t->n; delete t; t=pr->n; continue; }
            pr->n=t->n; delete t; t=pr->n; continue;
        }
        pr=t; t=t->n;
    }while(t!=last2->n);
}

void showDL(){
    nd1 *t=h1;
    while(t){ cout<<t->d<<" "; t=t->n; }
    cout<<"\n";
}
void showCL(){
    if(last2==NULL){ cout<<"empty\n"; return; }
    nd2 *t=last2->n;
    do{ cout<<t->d<<" "; t=t->n; }while(t!=last2->n);
    cout<<"\n";
}

int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        addDL(x);
        addCL(x);
    }
    delEvenDL();
    delEvenCL();
    showDL();
    showCL();
}
