#include<iostream>
#include<vector>
using namespace std;

vector<int> a[1000];
int visited[1000];

void dfs(int k) {
    if(!visited[k]) {
        visited[k]=1;
        for(int i=0;i<a[k].size();i++) {
            if(!visited[a[k][i]]) 
                dfs(a[k][i]);
        }
    }
}

int main(void) {
    int n, e;
    cin>>n;
    while (e--)
    {
        int p,q;
        cin>>p>>q;
        a[p].push_back(q); //directed graph
    }
    
    int s, d;
    cin>>s>>d;
    dfs(s);

    if(visited[d]==1)
        cout<<"YES path exist"<<endl;
    else
        cout<<"NO path doesn't exist"<<endl;
    return 0; 
}