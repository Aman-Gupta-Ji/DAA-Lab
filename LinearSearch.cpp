#include<iostream>
using namespace std;
int lin_search(int [],int,int);
int main()
{
    int n;
    std::cout<<"Enter Length Of Array"<<"\n";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        std::cout<<"Enter "<<i+1<<" Element"<<"\n";
        cin>>arr[i];
    }
    int key;
    std::cout<<"Enter Element you want to find"<<"\n";
    cin>>key;
    for(int i=0; i<n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    int loc=lin_search(arr,n,key);
    std::cout<<"in main<"<<"\n";
    for(int i=0; i<n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    if (loc>=0)
        std::cout<<"Location of "<<key<<" is "<<loc<<"\n";
    else
        std::cout<<"Key is not found";
}
int lin_search(int arr[],int n,int key)
{
    std::cout<<"In fun"<<"\n";

    for(int i=0; i<n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";

    for(int i=0; i<n; i++)
    {
        arr[i]=1;
    }
    for(int i=0; i<n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    for(int i=0; i<n; i++)
    {
        if (arr[i]==key)
        {
            return i;
        }
    }
    
    return -1;
}