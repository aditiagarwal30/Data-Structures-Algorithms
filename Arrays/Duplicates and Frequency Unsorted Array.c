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

void Fun1(struct Array arr)
{
   for(int i=0;i<arr.length-1;i++)
   {
      int count=1;
      if(arr.A[i]!=-1)
      {
         for(int j=i+1;j<arr.length;j++)
            if(arr.A[i]==arr.A[j])
            {
               count++;
               arr.A[j]=-1;
            }

        if(count>1)
            printf("%d repeats %d times \n",arr.A[i],count);
      }
   }
}

int main()
{
 struct Array arr1={{2,1,8,1,5,7,9,8,1},10,9};
 Fun1(arr1);

 return 0;
}
