#include<bits/stdc++.h>
using namespace std;

struct nd{
    int d;
    nd *n;
};

nd *lst = NULL;

nd* makeNode(int v){
    nd *t = new nd;
    t->d = v;
    t->n = NULL;
    return t;
}

void addBeg(int v){
    nd *p = makeNode(v);
    if(lst==NULL){
        lst=p;
        lst->n=lst;
    } else {
        p->n = lst->n;
        lst->n = p;
    }
}

void addEnd(int v){
    nd *p = makeNode(v);
    if(lst==NULL){
        lst=p;
        lst->n=lst;
    } else {
        p->n = lst->n;
        lst->n = p;
        lst = p;
    }
}

void addAfter(int k,int v){
    if(lst==NULL) return;
    nd *t = lst->n;
    do{
        if(t->d==k){
            nd *p = makeNode(v);
            p->n = t->n;
            t->n = p;
            if(t==lst) lst = p;
            return;
        }
        t=t->n;
    }while(t!=lst->n);
    cout<<"nope\n";
}

void addBefore(int k,int v){
    if(lst==NULL) return;
    nd *t=lst->n, *pr=lst;
    do{
        if(t->d==k){
            nd *p = makeNode(v);
            p->n=t;
            pr->n=p;
            if(t==lst->n) lst->n=p;
            return;
        }
        pr=t;
        t=t->n;
    }while(t!=lst->n);
    cout<<"nope\n";
}

void delIt(int k){
    if(lst==NULL){
        cout<<"empty\n";
        return;
    }
    nd *t=lst->n,*pr=lst;
    if(lst==lst->n && lst->d==k){
        delete lst;
        lst=NULL;
        return;
    }
    do{
        if(t->d==k){
            pr->n = t->n;
            if(t==lst) lst=pr;
            if(t==lst->n) lst->n=t->n;
            delete t;
            return;
        }
        pr=t;
        t=t->n;
    }while(t!=lst->n);
    cout<<"nope\n";
}

void findIt(int k){
    if(lst==NULL){
        cout<<"empty\n";
        return;
    }
    nd *t=lst->n;
    int c=1;
    do{
        if(t->d==k){
            cout<<"found "<<c<<"\n";
            return;
        }
        t=t->n;
        c++;
    }while(t!=lst->n);
    cout<<"nope\n";
}

void show(){
    if(lst==NULL){
        cout<<"empty\n";
        return;
    }
    nd *t=lst->n;
    do{
        cout<<t->d<<" ";
        t=t->n;
    }while(t!=lst->n);
    cout<<"\n";
}

int main(){
    int ch,a,b;
    for(;;){
        cout<<"\n1 addBeg\n2 addEnd\n3 addAfter\n4 addBefore\n5 del\n6 find\n7 show\n8 quit\n";
        cin>>ch;
        if(ch==8) break;
        if(ch==1){cin>>a; addBeg(a);}
        else if(ch==2){cin>>a; addEnd(a);}
        else if(ch==3){cin>>a>>b; addAfter(a,b);}
        else if(ch==4){cin>>a>>b; addBefore(a,b);}
        else if(ch==5){cin>>a; delIt(a);}
        else if(ch==6){cin>>a; findIt(a);}
        else if(ch==7) show();
        else cout<<"wrong\n";
    }
}
