#include<bits/stdc++.h>
using namespace std;

struct nd{
    int d;
    nd *p,*n;
};

nd *head=NULL,*tail=NULL;

nd* mk(int v){
    nd *t=new nd;
    t->d=v;
    t->p=t->n=NULL;
    return t;
}

void addBeg(int v){
    nd *t=mk(v);
    if(head==NULL){
        head=tail=t;
    } else {
        t->n=head;
        head->p=t;
        head=t;
    }
}

void addEnd(int v){
    nd *t=mk(v);
    if(tail==NULL){
        head=tail=t;
    } else {
        tail->n=t;
        t->p=tail;
        tail=t;
    }
}

void addAfter(int k,int v){
    if(head==NULL) return;
    nd *x=head;
    while(x){
        if(x->d==k){
            nd *t=mk(v);
            t->n=x->n;
            t->p=x;
            if(x->n) x->n->p=t;
            x->n=t;
            if(x==tail) tail=t;
            return;
        }
        x=x->n;
    }
    cout<<"nope\n";
}

void addBefore(int k,int v){
    if(head==NULL) return;
    nd *x=head;
    while(x){
        if(x->d==k){
            nd *t=mk(v);
            t->n=x;
            t->p=x->p;
            if(x->p) x->p->n=t;
            x->p=t;
            if(x==head) head=t;
            return;
        }
        x=x->n;
    }
    cout<<"nope\n";
}

void delIt(int k){
    if(head==NULL){
        cout<<"empty\n";
        return;
    }
    nd *x=head;
    while(x){
        if(x->d==k){
            if(x==head && x==tail){
                head=tail=NULL;
            } else if(x==head){
                head=head->n;
                head->p=NULL;
            } else if(x==tail){
                tail=tail->p;
                tail->n=NULL;
            } else {
                x->p->n=x->n;
                x->n->p=x->p;
            }
            delete x;
            return;
        }
        x=x->n;
    }
    cout<<"nope\n";
}

void findIt(int k){
    nd *x=head;
    int c=1;
    while(x){
        if(x->d==k){
            cout<<"found "<<c<<"\n";
            return;
        }
        x=x->n;
        c++;
    }
    cout<<"nope\n";
}

void showF(){
    nd *x=head;
    while(x){
        cout<<x->d<<" ";
        x=x->n;
    }
    cout<<"\n";
}

void showB(){
    nd *x=tail;
    while(x){
        cout<<x->d<<" ";
        x=x->p;
    }
    cout<<"\n";
}

int main(){
    int ch,a,b;
    for(;;){
        cout<<"\n1 addBeg\n2 addEnd\n3 addAfter\n4 addBefore\n5 del\n6 find\n7 showF\n8 showB\n9 quit\n";
        cin>>ch;
        if(ch==9) break;
        if(ch==1){cin>>a;addBeg(a);}
        else if(ch==2){cin>>a;addEnd(a);}
        else if(ch==3){cin>>a>>b;addAfter(a,b);}
        else if(ch==4){cin>>a>>b;addBefore(a,b);}
        else if(ch==5){cin>>a;delIt(a);}
        else if(ch==6){cin>>a;findIt(a);}
        else if(ch==7) showF();
        else if(ch==8) showB();
        else cout<<"wrong\n";
    }
}
