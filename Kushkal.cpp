#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,pair<int,int>>> vii;

int findParent(int u,vector<int>& parent) {
    if(parent[u]<0) 
        return u;
    return parent[u]=findParent(parent[u],parent);
}

bool doUnion(int u, int v, vector<int>& parent) {
    int pu=findParent(u,parent);
    int pv=findParent(v,parent);
    if(pu==pv) {
        return false;
    }
    if(parent[u]<parent[v]) {
        parent[u]+=parent[v];
        parent[v]=pu;
    }
    else {
        parent[v]+=parent[u];
        parent[u]=pv;
    }
    return true;

}

vii krushals(vii g, int v) {
    vii res;
    int s, d, w;
    vector<int> parent(v,-1);
    sort(g.begin(),g.end());
    int E=g.size();
    for(int i=0;i<E;i++) {
        s=g[i].second.first;
        d=g[i].second.second;
        w=g[i].first;
        if(findParent(s,parent)!=findParent(d,parent)) {
            res.push_back(g[i]);
            doUnion(s,d,parent);
        }
    }
    return res;
}

int main(void) {
    int n, e;
    cin>>n>>e;
    vii g, res;
    int v, s, d, w;
    for(int i=0;i<e;i++) {
        cin>>s>>d>>w;
        g.push_back(make_pair(w,make_pair(s,d)));
    }
    res=krushals(g, n);
    int sum=0;
    for(int i=0;i<res.size();i++) {
        int w=res[i].first;
        cout<<res[i].second.first<<" "<<res[i].second.second<<endl;
        sum+=w;
    }
    cout<<"Sum of weights = "<<sum<<endl;
    return 0;
}