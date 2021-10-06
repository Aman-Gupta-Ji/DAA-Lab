#include<bits/stdc++.h>
using namespace std;
int NoMinChange(vector<int> coins, int n) { //Smallest non constructable value
    sort(coins.begin(),coins.end());
    int max_construct=0;
    for(int a : coins) {
        if(a>max_construct+1)
            break;
        max_construct+=a;
    }
    return max_construct+1;
}
int main(void) {
    int n, i, c;
    cin>>n;
    vector<int> coins;
    for(i=0;i<n;i++) {
        cin>>c;
        coins.push_back(c);
    }
    int min=NoMinChange(coins,n);
    cout<<min<<endl;
}