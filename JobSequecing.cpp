#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef struct job{
    string jo;
    int profit, dead;
}job;

int compare(const void* a,const void* b) {
    return (((job*)b)->profit - ((job*)a)->profit);
}

int main(void) {
    int n;
    cin>>n;
    job jobs[n];
    for(int i=0;i<n;i++) {
        cin>>jobs[i].jo>>jobs[i].profit>>jobs[i].dead;
    }
    int max=jobs[0].dead;
    for(int i=1;i<n;i++) {
        if(max<jobs[i].dead)
            max=jobs[i].dead;
    }

    qsort(jobs, n, sizeof(job), compare);
    cout<<"\n------------------------"<<"\n\tsorted"<<endl;
    for(int i=0;i<n;i++) {
        cout<<jobs[i].jo<<"\t"<<jobs[i].profit<<"\t"<<jobs[i].dead<<endl;
    }
    cout<<endl;

    vector<int> result(max+1,-1);
    int i, j;
    for(i=0;i<n;i++) {
        for(j=jobs[i].dead;j>=0;j--) {
            if(result[j]==-1) {
                result[j]=i;
                break;
            }
        }
    }
    long sum=0;
    for(i=0;i<=max;i++) {
        cout<<i<<": ";
        if(result[i]!=-1) {
            cout<<jobs[result[i]].jo<<" = "<<jobs[result[i]].profit<<endl;
            sum+=jobs[result[i]].profit;
        }
        else
            cout<<"-1"<<endl;
    }
    cout<<"\nMax profit = "<<sum<<endl<<endl;
    return 0;
}