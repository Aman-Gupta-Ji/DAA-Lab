#include<bits/stdc++.h>
using namespace std;

int knapSack(int ind, int w, int val[], int wt[], int n) { //T.C. = O(2^n)
    if(ind>=n) return 0;
    if(w==0) return 0; // bag is full

    if(wt[ind]<=w) {
        int left=val[ind]+knapSack(ind+1,w-wt[ind],val,wt,n);
        int right=knapSack(ind+1,w,val,wt,n);
        return max(left,right);
    }
    else
        return knapSack(ind+1,w,val,wt,n);
}

int knapSack(int ind, int w, int val[], int wt[], int n, vector<vector<int>>& dp) { // T.C. = O(n*wt)   S.C. = O(n*wt)
    if(ind>=n)  return 0;
    if(w==0) return 0;

    if(dp[ind][w]!=-1)  return dp[ind][w];

    if(wt[ind]<=w) {
        int left=val[ind]+knapSack(ind+1,w-wt[ind],val,wt,n,dp);
        int right=knapSack(ind+1,w,val,wt,n);
        return dp[ind][w]=max(left,right);
    }
    else
        return dp[ind][w]=knapSack(ind+1,w,wt,val,n);
}
int main() {
    int n;
    cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++) {
        int w,v;
        cin>>w>>v;
        wt[i]=w;
        val[i]=v;
    }
    int weight;
    cin>>weight;
    vector<vector<int>> dp(n,vector<int> (weight+1,-1));
    //cout<<knapSack(0,weight,val,wt,n);
    cout<<knapSack(0,weight,val,wt,n,dp);
    return 0;
}