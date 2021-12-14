#include<bits/stdc++.h>
using namespace std;

void path(vector<int> & parent, int i) {
    if(parent[i]==-1) {
        cout<<i;
        return;
    }
    cout<<i<<" - ";
    path(parent, parent[i]);
}

int main(void) {
    int n, e;
    cin>>n>>e;
    int u, v, w;
    vector<vector<int>> edges;
    for(int i=0;i<e;i++) {
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }
    vector<int> parent(n+1,-1);
    vector<int> dist(n+1,1e9);
    int src;
    cin>>src;
    dist[src]=0;
    bool ncycle=false;
    for(int i=1;i<n;i++) {
        ncycle=false;
        for(auto it: edges) {
            u=it[0];
            v=it[1];
            w=it[2];
            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                parent[v]=u;
                ncycle=true;
            }
        }
    }
    if(ncycle)
        cout<<"Negative cycle detected"<<endl;
    else {
        for(int i=1;i<n+1;i++) {
            path(parent,i);
            cout<<" : "<<dist[i]<<endl;
        }
    }
}