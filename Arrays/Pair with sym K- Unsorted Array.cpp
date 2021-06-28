#include<stdio.h>
#include<stdlib.h>
struct Array
{
 int A[15];
 int size;
 int length;
};

void Sum_k(struct Array arr, int k)
{
    int i=0,j=arr.length-1;
    while(i<j)
    {
        if(arr.A[i]+arr.A[j]==k)
            {
                printf("%d + %d = %d\n",arr.A[i],arr.A[j],k);
                i++;
                j--;
            }
        else if(arr.A[i]+arr.A[j]<k)
            i++;
        else
            j--;
    }
}

int main()
{
 struct Array arr1={{1,3,4,5,6,8,9,12,14,10,9},15,11};
 int key;
 scanf("%d",&key);

 Sum_k(arr1,key);

 return 0;
}
