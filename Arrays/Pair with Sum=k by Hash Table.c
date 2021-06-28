#include <stdio.h>
#include<stdlib.h>

struct Array
{
 int A[10];
 int size;
 int length;
};

void Fun1(struct Array arr,int k)
{
	int l=arr.A[0],h=0;
	for (int i = 0; i < arr.length; ++i)
	{
		if(arr.A[i]<l)
			l=arr.A[i];
		if(arr.A[i]>h)
			h=arr.A[i];
    }

    int *H=(int *)calloc(h+1,sizeof(int));

    for(int i=0;i<arr.length;i++)
    {
    	if(H[k-arr.A[i]]!=0)
    		printf("%d + %d = %d\n",arr.A[i],k-arr.A[i],k);
    	H[arr.A[i]]++;
    }
}

int main()
{
 struct Array arr1={{1,9,2,4,5,5,8,10,6},10,9};
 int key;
 scanf("%d",&key);
 Fun1(arr1,key);

 return 0;
}    