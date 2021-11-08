#include<bits/stdc++.h>
using namespace std;

int matRecursive(vector<int> mat, int i, int j) {   //T.C. = O(2^n) S.C. = O(n)
    if(i==j)
        return 0;
    int k;
    int min=INT_MAX;
    int count;
    for(k=i;k<j;k++) {
        count=matRecursive(mat,i,k)+matRecursive(mat,k+1,j)+mat[i-1]*mat[k]*mat[j];
        if(count<min) {
            min=count;
        }
    }
    return min;
}

int memoization(vector<int> mat, vector<vector<int>> dp, int i, int j) {
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=INT_MAX;
    int k, count;
    for(k=i;k<j;k++) {
        count=memoization(mat,dp,i,k)+memoization(mat,dp,k+1,j)+mat[i-1]*mat[k]*mat[j];
        if(count<dp[i][j]) {
            dp[i][j]=count;
        }
    }
    return dp[i][j];
}

int matMemoization(vector<int> mat, int n) {
    int i=1, j=n;
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    return memoization(mat,dp,i,j);
}

int matTabulation(vector<int> mat, int n) {
    vector<vector<int>> dp(n+1,vector<int> (n+1));

}

int main(void) {
    int n, temp;
    cin>>n;
    vector<int> mat(n+1);
    for(int i=0;i<=n;i++) {
        cin>>temp;
        mat[i]=temp;
    }
    int result=matRecursive(mat,1,n);
    return 0;
}