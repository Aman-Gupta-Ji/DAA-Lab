#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
    vector<pair<int,int>> activity; // pair< end_time , start_time >
    int n, s, e;
    cout<<"Enter the no. of activities : ";
    cin>>n;
    cout<<"\nEnter Start_time and End_Time of each activity "<<endl;
    int i;
    for(i=0;i<n;i++) {
        cin>>s>>e;
        activity.push_back(make_pair(e,s));
    }

    sort(activity.begin(),activity.end()); // sort according to the end time

    int count; // count the no of activity that can be run in a uniprocessor
    int pcount=0; // No. of uniprocessor required to complete each activity
    int current_end;
    vector<bool> comp(n,false); // track of activites that are completed
    int completed=0; // activites that are completed

    while(completed!=n) {
        pcount++;
        current_end=-1;
        count=0;
        cout<<"\nProcessor No. "<<(pcount+1)<<endl;

        for(i=0;i<n;i++) {
            if(!comp[i]&&activity[i].second>current_end) {
                count++;
                current_end=activity[i].first;
                completed++;
                comp[i]=true;
                cout<<activity[i].second<<"\t"<<activity[i].first<<endl;
            }
        }
        cout<<"No. of activity completed : "<<count<<endl;
    }
    cout<<"\nNo. of Uniprocessors requried to complete each activity : "<<pcount<<endl;
    return 0;
}
/* OUTPUT
Enter the no. of activities : 7

Enter Start_time and End_Time of each activity 
1 2
0 6
3 4
7 9
5 9
5 7
8 9

Processor No. 2
1       2
3       4
5       7
8       9
No. of activity completed : 4

Processor No. 3
0       6
7       9
No. of activity completed : 2

Processor No. 4
5       9
No. of activity completed : 1

No. of Uniprocessors requried to complete each activity : 3
*/