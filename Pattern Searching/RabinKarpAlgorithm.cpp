#include<bits/stdc++.h>
using namespace std;

void RabinKarp(string txt, string pat) {
    int d, q;
    cin>>d>>q;
    int n=txt.length();
    int m=pat.length();
    int h=1; // d^m-1;
    int i, j;

    for(i=1;i<m;i++)
        h=(h*d)%q;
    
    int sh=0; //spurious hits
    int hit, match;
    hit=match=0;

    int hpat, hwin; // hash_pattern   hash_window
    hpat=hwin=0;

    for(i=0;i<m;i++) {
        hpat=(hpat*d+pat[i])%q;
        hwin=(hwin*d+txt[i])%q;
    }
    printf("\nhash pat = %d\n",hpat);
    printf("\nhash window = %d",hwin);

    for(i=0;i<=n-m;i++) {
        if(hpat==hwin) {
            hit++;
            for(j=0;j<m;j++) {
                if(pat[j]!=txt[i+j])
                    break;
            }
            if(j==m) {
                printf("\n%d",i);
                match++;
            }
            else
                sh++;
        }
        hwin=((d*(hwin-(h*txt[i])%q))%q+txt[i+m]%q)%q;

        /*
        if(i<n-m) {
            hwin=(d*(hwin-txt[i]*h)+txt[i+m])%q;
            if(hwin<0)
                hwin=hwin+q;
        }
        */

        printf("\nhash window = %d",hwin);
        
    }
    printf("\nhits = %d\nmatch = %d\nspurious hits = %d\n",hit,match,sh);
}

int main(void) {
    string pat, txt;
    cin>>txt>>pat;
    RabinKarp(txt,pat);
    return 0;
}