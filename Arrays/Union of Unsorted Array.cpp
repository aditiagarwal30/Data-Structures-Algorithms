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
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
 int i=0,j=0,k=0;
 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

 for(i=0;i<arr1->length;i++)
 {
    arr3->A[k]=arr1->A[i];
    k++;
 }
 for(j=0;j<arr2->length;j++)
 {  int m;
    for(m=0;m<k;m++)
        if(arr2->A[j]==arr3->A[m])
            break;
    if(m==k)
       arr3->A[k++]=arr2->A[j];
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
    arr3=Union(&arr1,&arr2);
    Display(*arr3);
return 0;

}
