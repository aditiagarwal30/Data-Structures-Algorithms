#include <bits/stdc++.h>
using namespace std;

struct Array
{
 int A[10];
 int size;
 int length;
};

void Missing(struct Array arr)
{
	int l=arr.A[0],h=0;
	for (int i = 0; i < arr.length; ++i)
	{
		if(arr.A[i]<l)
			l=arr.A[i];
		if(arr.A[i]>h)
			h=arr.A[i];
    }

    int *H=(int *)calloc(h,sizeof(int));
    for(int i=0;i<arr.length;i++)
    {
    	H[arr.A[i]]++ ;
    }
    for(int i=l;i<=h;i++)
    	if(H[i]==0)
    		cout<<"Missing Element is : "<<i<<endl;
}

int main()
{
 struct Array arr1={{2,1,7,4,5,3,9,10,8},10,9};
 Missing(arr1);

 return 0;
}
