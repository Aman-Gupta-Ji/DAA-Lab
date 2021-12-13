#include<stdio.h>
#include<stdlib.h>
int* MergeSort(int *ar, int l, int r) {
    int n=r-l;
    if(n==1||n==0)  return;
    int mid=l-(l-r)/2;
    int * left=MergeSort(ar,l,mid);
    int * right=MergeSort(ar,mid+1,r);
    int * ret=(int *)malloc(sizeof(int)*n);
    int ll=mid-l, rl=r-(mid+1);
    int lp=0, rp=0, p=0;
    while(ll!=0||rl!=0) {
        if(left[lp]<right[rp]) {
            ret[p++]=left[lp++];
            ll--;
        }
        else {
            ret[p++]=right[rp++];
            rl--;
        }
    }
    while(ll!=0) {
        ret[p++]=left[lp++];
        ll--;
    }
    while(rl!=0) {
        ret[p++]=right[rl++];
        rl--;
    }
    free(left);
    free(right);
    return ret;
}
int main(void) {
    int t;
    int n, i;
    int *ret;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int ar[n];
        for(i=0;i<n;i++) {
            scanf("%d",&ar[i]);
        }
        ret=MergeSort(ar,0,n);
        printf("\n");
        for(i=0;i<n;i++) {
            printf("%d\t",ret[i]);
        }
        free(ret);
        printf("\n");
    }
    return 0;
}
/*
3
8
23 65 21 76 46 89 45 32
10
21 32 34 46 51 54 65 76 78 97
15
63 42 223 645 652 31 324 22 553 12 54 65 86 46 325
*/