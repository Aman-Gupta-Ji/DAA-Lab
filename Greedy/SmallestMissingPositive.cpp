#include<bits/stdc++.h>
using namespace std;
int On(vector<int> A, int n) {// T.C.=O(n) S.C.=O(1)
//record which values are present by writing A[i] to index A[i]-1 if A[i] is between A and size(A), inclusive.
//we save the value at index A[i]-1 with A[i] if A[i] is -ve or greater than i we just advance out i
    int temp;
    for(int i=0;i<n;i++) {
        while(0<A[i]&&A[i]<=n&&A[i]!=A[A[i]-1]) {
            // swap(A[i],A[A[i]-1])
            temp=A[i];
            A[i]=A[A[i]-1];
            A[temp-1]=temp;
        }
        //second pass through A to search for the first index i such that A[i]!=A[i]+1 indicating that i+1 is absent
        //is all numbers between 1 and size(A) are present then smallest present is size(A)+1
        cout<<A<<endl;
    }
    for(int i=0;i<n;i++) {
        if(A[i]!=i+1) {
            return i+1;
        }
    }
    return n+1;

}
int Onlogn(vector<int> arr, int n) { //T.C.=O(nlogn) S.C.=O(1)
    sort(arr.begin(),arr.end());
    int pres=1;
    for(int i=0;i<n;i++) {
        if(arr[i]<pres)
            continue;
        if(arr[i]==pres)
            pres++;
        else 
            break;
    }
    return pres;
}
int OnUnorderedSet(vector<int> arr, int n) { //T.C.= O(n)  S.C.=O(n)
    unordered_set<int> hashset;
    for(int i=0;i<n;i++) {
        hashset.insert(arr[i]);
    }
    int pres=1;
    for(int i=0;i<n;i++) {
        if(hashset.find(pres)!=hashset.end())
            pres++;
        else
            break;
    }
    return pres;
}
int main(void) {
    int n, i, temp;
    cin>>n;
    vector<int> arr;
    for(i=0;i<n;i++) {
        cin>>temp;
        arr.push_back(temp);
    }
    int ans=On(arr,n);
    cout<<ans<<endl;
}