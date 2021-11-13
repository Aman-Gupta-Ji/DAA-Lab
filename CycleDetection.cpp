#include<bits/stdc++.h>
using namespace std;

int find(int u, vector<int>& parent) {
    if(parent[u]<0) 
        return u;
    parent[u]= find(parent[u],parent);
    return parent[u];
}

bool unionByWeight(int u, int v , vector<int>& parent) {
    int pu=find(u,parent);
    int pv=find(v,parent);
    // cout<<pu<<" "<<pv<<endl;
    if(pu==pv)
        return false;
    // cout<<"NO error";
    if(parent[pu]<parent[pv]) {
        parent[pu]+=parent[pv];
        parent[pv]=pu;
    }
    else {
        parent[pv]+=parent[pu];
        parent[pu]=pv;
    }
    return true;
}
void print (vector<int> p, int n) {
    for(int i=0;i<n;i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
int main(void) {
    int n;
    cin>>n;
    vector<int> p(n,-1);
    print(p,n);

    int e;
    cin>>e;
    int s,d;
    int i;
    for(i=0;i<e;i++) {
        cin>>s>>d;
        // cout<<i<<endl;
        bool res=!unionByWeight(s,d,p);
        print(p,n);
        // cout<<res<<endl;
        if(res) {
            cout<<"cycle detected"<<endl;
        }
    }   

    return 0;
}
/*
8
8
1 2
1 4
4 3
2 3
2 5
5 6
6 7
5 7

*/