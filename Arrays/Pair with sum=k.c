#include<stdio.h>
#include<stdlib.h>
struct Array
{
 int A[10];
 int size;
 int length;
};

void Fun1(struct Array arr,int k)
{
   for(int i=0;i<arr.length-1;i++)
      for(int j=i+1;j<arr.length;j++)
         if(arr.A[i]+arr.A[j]==k)
            printf("%d + %d = %d \n",arr.A[i],arr.A[j],k);

}

int main()
{
 struct Array arr1={{4,1,8,3,5,7,9,6,10},10,9};
 int key;
 scanf("%d",&key);
 Fun1(arr1,key);

 return 0;
}
