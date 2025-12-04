//prims

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<int> vis(n,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    long long ans=0;
    while(!pq.empty()){
        auto x=pq.top(); pq.pop();
        int w=x.first, u=x.second;
        if(vis[u]) continue;
        vis[u]=1;
        ans+=w;
        for(auto &p:adj[u]){
            pq.push({p.second,p.first});
        }
    }
    cout<<ans<<"\n";
}
