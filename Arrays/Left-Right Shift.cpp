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

void Left_Shift(struct Array *arr)
{
    for(int i=0;i<arr->length-1;i++)
        arr->A[i]=arr->A[i+1];
}

void Right_Shift(struct Array *arr)
{
    for(int i=arr->length-1;i>0;i--)
        arr->A[i]=arr->A[i-1];
}

int main()
{
 struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
 printf("\nOriginal Array:");
 Display(arr1);
 Left_Shift(&arr1);
 printf("\nLeft shifted Array:");
 Display(arr1);
 Right_Shift(&arr1);
 printf("\nRight shifted Array:");
 Display(arr1);
 return 0;
}
