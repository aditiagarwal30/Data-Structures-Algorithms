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

void Duplicates(struct Array arr)
{
   int last_duplicate=0;
   for(int i=0;i<arr.length;i++)
   {
      if(arr.A[i]==arr.A[i+1] && arr.A[i]!=last_duplicate)
      {
         printf("Duplicate : %d\n",arr.A[i]);
         last_duplicate=arr.A[i];
      }
   }
}

int main()
{
 struct Array arr1={{1,2,2,4,5,7,9,9,9},10,9};
 Duplicates(arr1);

 return 0;
}
