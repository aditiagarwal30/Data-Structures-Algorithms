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

void Frequency(struct Array arr)
{
      for(int i=0;i<arr.length-1;i++)
   {
      if(arr.A[i]==arr.A[i+1])
      {
         int j=i+1;
         while(arr.A[j]==arr.A[i])
            j++;
         printf("%d repeats %d times \n",arr.A[i],j-i);
         i=j-1;
      }
   }
}

int main()
{
 struct Array arr1={{1,1,1,1,5,7,9,9,9},10,9};
 Frequency(arr1);

 return 0;
}
