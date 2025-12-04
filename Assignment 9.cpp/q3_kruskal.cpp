//kruskal

#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> p, r;
    DSU(int n){
        p.resize(n);
        r.assign(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }
    int findp(int x){
        if(p[x]==x) return x;
        return p[x]=findp(p[x]);
    }
    void unite(int a,int b){
        a=findp(a);
        b=findp(b);
        if(a!=b){
            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<array<int,3>> edges;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back({w,a,b});
    }
    sort(edges.begin(),edges.end());
    DSU d(n);
    long long ans=0;
    for(auto &e:edges){
        int w=e[0], a=e[1], b=e[2];
        if(d.findp(a)!=d.findp(b)){
            d.unite(a,b);
            ans+=w;
        }
    }
    cout<<ans<<"\n";
}
