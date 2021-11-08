#include<bits/stdc++.h>
using namespace std;

void patSearching(string & txt, string & pat) {
    int m=pat.length();
    int n=txt.length();
    int i, j;
    int count=0;
    cout<<endl;
    for(i=0;i<=n-m;i++) {
        for(j=0;j<m;j++) {
            if(pat[j]!=txt[i+j])
                break;
        }
        if(j==m) {
            cout<<i<<endl;
            count++;
        }
        if(count==0)
            cout<<"Not present"<<endl;
    }
}

int main(void) {
    string pat, txt;
    cin>>txt>>pat;
    patSearching(txt,pat);
    return 0;
}