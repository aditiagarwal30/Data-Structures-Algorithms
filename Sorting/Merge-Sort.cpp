#include<iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int h)
{
    int n1= mid-l+1;
    int n2= h-mid;
    
    int a[n1];
    int b[n2];
    
    for(int i=0;i<n1;i++)
        a[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        b[i]=arr[mid+1+i];
        
    int i=0,j=0,k=l;
    
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;   
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}

void MergeSort(int *a, int l, int h)
{
    if(l>=h)
            return;
            
            int mid=(l+h)/2;
            
            MergeSort(a,l,mid);
            MergeSort(a,mid+1,h);
            
            Merge(a,l,mid,h);
}

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    MergeSort(arr,0,n-1);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;    
}