//enen length cycle graph is bipartite
//odd lengthe cycle graph is not bipartite

#include<bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    if(color[node]==-1)
        color[node]=1;
    
    for(int it: adj[node]) {
        if(color[it]==-1) {
            color[it]=1-color[node];
            if(!bipartiteDfs(it, adj, color))
                return false;
        }
        else if(color[it]==color[node])
            return false;
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++) {
        if(color[i]==-1) {
            if(!bipartiteDfs(i,adj,color))
                return false;
        }
    }
    return true;
}

int main(void) {
    int n, m;
    cin>>n>>m;
    int u, v;
    vector<int> adj[n];
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkBipartite(adj,n))
        cout<<"Yes Bipartite"<<endl;
    else
        cout<<"Not Bipartite"<<endl;
    return 0;
}