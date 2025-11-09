#include<bits/stdc++.h>
using namespace std;

struct nd{
    int d;
    nd *l,*r,*u,*dwn;
};

nd* mk(int v){
    nd *x=new nd;
    x->d=v;
    x->l=x->r=x->u=x->dwn=NULL;
    return x;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<nd*>> a(n, vector<nd*>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x; cin>>x;
            a[i][j]=mk(x);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j>0) a[i][j]->l=a[i][j-1];
            if(j<m-1) a[i][j]->r=a[i][j+1];
            if(i>0) a[i][j]->u=a[i-1][j];
            if(i<n-1) a[i][j]->dwn=a[i+1][j];
        }
    }

    for(int i=0;i<n;i++){
        nd *t=a[i][0];
        while(t){
            cout<<t->d;
            if(t->r) cout<<" <-> ";
            t=t->r;
        }
        cout<<" -> NULL\n";
    }
}
