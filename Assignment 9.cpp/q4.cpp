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
    }
    int src;
    cin>>src;
    vector<long long> dist(n,1e18);
    dist[src]=0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto x=pq.top(); pq.pop();
        long long d=x.first;
        int u=x.second;
        if(d!=dist[u]) continue;
        for(auto &p:adj[u]){
            int v=p.first;
            long long w=p.second;
            if(dist[v] > d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
}
