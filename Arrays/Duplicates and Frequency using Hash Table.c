#include <stdio.h>
#include<stdlib.h>

struct Array
{
 int A[10];
 int size;
 int length;
};

void Fun1(struct Array arr)
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
    	H[arr.A[i]]++ ;
    }

    for(int i=l;i<=h;i++)  //duplicates
    	if(H[i]>1)
    		printf("Duplicate Elements : %d\n", i);

    for(int i=0;i<=h;i++)   //frequency of elements
       if(H[i]>=1)
          printf("Frequency of %d is %d\n",i,H[i]);
}

int main()
{
 struct Array arr1={{2,9,2,4,5,3,9,10,2},10,9};
 Fun1(arr1);

 return 0;
}
