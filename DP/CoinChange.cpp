#include<bits/stdc++.h>
using namespace std;

int countRecursive(int ind, int sum, vector<int> S, int n) {
    if(sum==0)
        return 1;
    if(ind>=n||sum<0)
        return 0;
    int left=countRecursive(ind, sum-S[ind], S, n);
    int right=countRecursive(ind, sum, S, n);
    return left+right;
}

// int countMemoization(int )
int main(void) {
    int n;
    cin>>n;
    vector<int> S(n);
    int temp;
    for(int i=0;i<n;i++) {
        cin>>temp;
        S[i]=temp;
    }
    int sum;
    cin>>sum;
    int result=countRecursive(0,sum,S,n);
    cout<<result<<endl;
    
}