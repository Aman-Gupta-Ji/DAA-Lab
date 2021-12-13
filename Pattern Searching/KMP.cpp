#include<bits/stdc++.h>
using namespace std;
vector<int> lpsArray(string & pat, int m) {
    vector<int> lps(m);
    lps[0]=0;
    int i=1, len=0;
    while(i<m) {
        if(pat[i]==pat[len]) {
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if(len!=0)
                len=lps[len-1];
            else {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
void kmp(string & txt, string & pat) {
    int m = pat.length();
    int n = txt.length();
    int i, j;
    int count=0;
    vector<int> lps = lpsArray(pat,m);
    cout<<"lps array"<<endl;
    for(i=0;i<pat.length();i++) {
        cout<<lps[i]<<" ";
    }
    cout<<endl;
    i=j=0;
    while(i<n) {
        if(txt[i]==pat[j]) {
            j++;
            i++;
        }
        if(j==m) {
            j=lps[m-1];
            cout<<(i-m)<<endl;
            count++;
            continue;
        }
        else if(i<n&&pat[j]!=txt[i]) {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
        
    }
    if(count==0)
        cout<<"Not present"<<endl;
}

int main(void) {
    string pat, txt;
    cin>>txt>>pat;
    kmp(txt,pat);
    return 0;
}