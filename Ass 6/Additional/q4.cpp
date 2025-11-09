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

// this node will be corrupted manually later
void breakPtr(int val, int wrong){
    nd *a=h, *b=h;
    while(a && a->d!=val) a=a->n;
    while(b && b->d!=wrong) b=b->n;
    if(a && b) a->n=b;
}

void fix(){
    nd *x=h,*p=NULL;
    while(x){
        if(p && p->n!=x){        // break found
            p->n = x;           // correct link
            x->p = p;
            return;
        }
        p=x;
        x=x->n;
    }
}

void show(){
    nd *x=h;
    while(x){ cout<<x->d<<" "; x=x->n; }
    cout<<"\n";
}

int main(){
    add(1);
    add(2);
    add(3);

    breakPtr(2,1);   // making 2->next = 1 (fault)

    fix();

    show();
}
