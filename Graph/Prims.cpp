#include<bits/stdc++.h>
using namespace std;
typedef struct prims {
    int key, parent;
} vertex;
typedef vector<pair<int,int>> vii;

bool cmp(vertex &a, vertex &b) {
    return (a.key>b.key);
}
vector<vertex> prims(vector<vii>& g, int src,int v) {
    vector<vertex> res(v);
    int i;
    for(i=0;i<v;i++) {
        res[i].key=INT_MAX;
        res[i].parent=-1;
    }
    priority_queue<vertex> q();
    return res;
}
int main(void) {
    int n,e;
    cin>>n>>e;
    int s, d, w;
    vector<vii> g(n);
    int i;
    for(i=0;i<e;i++) {
        cin>>s>>d>>w;
        g[s].push_back(make_pair(d,w));
        g[d].push_back(make_pair(s,w));
    }
    vector<vertex> res=prims(g,0,n);
    
}