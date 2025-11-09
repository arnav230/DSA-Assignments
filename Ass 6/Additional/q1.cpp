#include<bits/stdc++.h>
using namespace std;

struct nd{
    int d;
    nd *n;
};

nd *lastptr=NULL;

nd* mk(int v){
    nd *t=new nd;
    t->d=v;
    t->n=NULL;
    return t;
}

void addEnd(int v){
    nd *p=mk(v);
    if(lastptr==NULL){
        lastptr=p;
        p->n=p;
    } else {
        p->n=lastptr->n;
        lastptr->n=p;
        lastptr=p;
    }
}

void split(nd *last, nd* &a, nd* &b){
    if(last==NULL) return;
    nd *s=last->n,*f=last->n;
    while(f->n!=last->n && f->n->n!=last->n){
        s=s->n;
        f=f->n->n;
    }
    a = last->n;
    b = s->n;
    s->n = a;
    nd *t=b;
    while(t->n!=last->n) t=t->n;
    t->n=b;
}

void show(nd *last){
    if(last==NULL){ cout<<"empty\n"; return;}
    nd *t=last->n;
    do{
        cout<<t->d<<" ";
        t=t->n;
    }while(t!=last->n);
    cout<<"\n";
}

int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        addEnd(x);
    }
    nd *h1=NULL,*h2=NULL;
    split(lastptr,h1,h2);
    show(h1);
    show(h2);
}
