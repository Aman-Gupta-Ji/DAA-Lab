/*Given a number n, write a program to find the nth ugly number.
Ugly numbers are those numbers whose only prime factors are 2, 3 or 5.
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20....

Input   : n=15
Output  : 24
*/
#include<bits/stdc++.h>
using namespace std;

int uglyNumber(int n) {
    vector<int> ugly(n);
    ugly[0]=1;
    int mul2, mul3, mul5;
    mul2=2;
    mul3=3;
    mul5=5;
    int p2, p3, p5;
    p2=p3=p5=0;
    int i=1, ug;
    while(i<n) {
        ug=min(mul2, min(mul3, mul5));
        ugly[i]=ug;
        if(ug==mul2) {
            p2++;
            mul2=ugly[p2]*2;
        }
        if(ug==mul3) {
            p3++;
            mul3=ugly[p3]*3;
        }
        if(ug==mul5) {
            p5++;
            mul5=ugly[p5]*5;
        }
        i++;
    }
    return ugly[n-1];
}
int main(void) {
    int n;
    cin>>n;
    int ug=uglyNumber(n);
    printf("%dth ugly number :\t %d\n",n,ug);
    return 0;
}
