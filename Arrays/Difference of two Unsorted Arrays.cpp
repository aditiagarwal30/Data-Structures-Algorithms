#include <stdio.h>
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
struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
 int i=0,j=0,k=0;
 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

 for(i=0;i<arr1->length;i++)
 {
   for(j=0;j<arr2->length;j++)
      if(arr1->A[i]==arr2->A[j])
             break;
   if(j==arr2->length)
      arr3->A[k++]=arr1->A[i];
}
 arr3->length=k;
 arr3->size=10;
 return arr3;
}

int main()
{
    struct Array arr1={{5,9,21,8,3},10,5};
    struct Array arr2={{12,3,9,8,8},10,5};
    struct Array *arr3;
    arr3=Difference(&arr1,&arr2);
    Display(*arr3);
return 0;

}
