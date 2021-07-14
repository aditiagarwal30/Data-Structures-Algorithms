#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],y[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int c=0,k=n-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            y[c]=a[i];
            c++;
        }
        else
        {
            y[k]=a[i];
            k--;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<y[i]<<" ";

}
