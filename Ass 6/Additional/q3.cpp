#include<bits/stdc++.h>
using namespace std;

struct nd{
    int d;
    nd *p,*n;
};

nd *h=NULL,*t=NULL;

nd* mk(int v){
    nd *x=new nd;
    x->d=v;
    x->p=x->n=NULL;
    return x;
}

void add(int v){
    nd *x=mk(v);
    if(h==NULL) h=t=x;
    else{ t->n=x; x->p=t; t=x; }
}

nd* revK(nd* head,int k){
    nd *c=head,*pr=NULL,*nx=NULL;
    int cnt=0;
    while(c && cnt<k){
        nx=c->n;
        c->n=pr;
        c->p=nx;
        pr=c;
        c=nx;
        cnt++;
    }
    if(nx){
        head->n=revK(nx,k);
        if(head->n) head->n->p=head;
    }
    return pr;
}

void show(){
    nd *x=h;
    while(x){ cout<<x->d<<" "; x=x->n; }
    cout<<"\n";
}

int main(){
    int n,k,x;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        add(x);
    }
    h=revK(h,k);
    show();
}
