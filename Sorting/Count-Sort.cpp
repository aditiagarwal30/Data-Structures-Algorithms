#include<iostream>
using namespace std;

void Count_Sort(int *arr, int n)
{
    int max= arr[0];
    
    for(int i=1;i<n;i++)
        if(arr[i]>max)
            max=arr[i];
            
    int count[max+1]={0};
    
    for(int i=0;i<n;i++)
        count[arr[i]]++;
    for(int i=0;i<=max;i++)
        count[i]+=count[i-1];
    
    int output[n];
    for(int i=n-1;i>=0;--i)
    {
        output[--count[arr[i]]]=arr[i];
    }
    
    for(int i=0;i<n;i++)
        arr[i]=output[i];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    Count_Sort(a,n);
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
    return 0;
}
