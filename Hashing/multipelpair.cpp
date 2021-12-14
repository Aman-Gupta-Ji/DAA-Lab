/* a*b = c*d
given an list of integers find the a such pair*/

#include<bits/stdc++.h>
using namespace std;

bool findpair(vector<int>& ar, int n) {
    map<int, pair<int, int> > Hash;
    int i, j, prod;
    pair<int, int> found;
    bool res=false;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            prod=ar[i]*ar[j];
            if(Hash.find(prod)==Hash.end())
                Hash[prod]=make_pair(ar[i],ar[j]);
            else {
                found=Hash[prod];
                printf("( %d \t*  %d \t)  =  ( %d \t*  %d \t)  =  %d\n",found.first,found.second,ar[i],ar[j],prod);
                res=true;
            }
        }
    }
    return res;
}
int main(void) {
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++) 
        cin>>ar[i];
    if(!findpair(ar,n))
        cout<<"No pair found"<<endl;
    return 0;
}