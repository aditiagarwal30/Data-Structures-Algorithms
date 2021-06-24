#include<stdio.h>
#include<stdlib.h>
struct Array
{
 int A[10];
 int size;
 int length;
};

 void Display(struct Array arr)
 {
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }

 void Neg_on_Left(struct Array arr)
 {
    int i=0,j=arr.length-1;

    while(i<j)
    {
        while(arr.A[i]<0)
            i++;
        while(arr.A[j]>0)
            j--;
        if(i,j)
            { int temp=arr.A[i];
              arr.A[i]=arr.A[j];
              arr.A[j]=temp;
            }

    }
    Display(arr);
 }

 int main()
{
 struct Array arr1={{2,-3,-9,16,-18,21,-28,-32,35},10,9};
 Neg_on_Left(arr1);
 return 0;
}
