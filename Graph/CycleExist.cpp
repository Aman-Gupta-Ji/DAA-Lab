#include<iostream>
#include<vector>
using namespace std;

vector<int> G[1000];
int flag;

void dfs(int u, int visited[]) {
    if(visited[u]==-1) {
        flag=1;
        return; // cycle detected
    }
    //if we reach the same node when it is being visited means cycle exist
    visited[u]=-1;
    for(int v: G[u]) {
        if(visited[v]!=1)
            dfs(v,visited);
    }
    visited[u]=1;
}

int main(void) {
    int nodes;
    cin>>nodes;
    int edges;
    cin>>edges;

    while (edges--) {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y); //directed graph
    }

    int visited[nodes+1];
    for(int i=1;i<=nodes;i++)
        visited[i]=0;
    /* Visited notation
    0   - means not visited
    1   - means finish visited
    -1  - means node is being visited */
    for(int i=1;i<=nodes;i++) {
        if(!visited[i])
            dfs(i,visited);
        if(flag==1)
            break;
    }
    if(flag)
        cout<<"Cycle exist"<<endl;
    else
        cout<<"Cycle doesn't exist"<<endl;
    return 0;
}