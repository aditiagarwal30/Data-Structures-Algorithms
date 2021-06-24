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

 void Insert( struct Array *arr,int x)
 {
    if (arr->length==arr->size)
    {
        return;
    }
    int i=arr->length -1;
    while(i>=0 && (arr->A[i]>x))
    {
       arr->A[i+1]=arr->A[i];
       i--;
    }
    arr->A[i+1]=x;
    arr->length++;
 }

int main()
{
 struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
 Insert(&arr1,20);
 Display(arr1);
 return 0;
}
