#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;
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

void Missing1(struct Array arr)
{
   int l= arr.A[arr.length-1];
   int sum= l*(l+1)/2;
   int sum_array=0;

   for(int i=0;i<arr.length;i++)
       sum_array+=arr.A[i];

   cout<<"Missing Element is : "<<sum - sum_array<<endl;

}

void Missing_n(struct Array arr)
{
   int diff= arr.A[0]-0;
   for(int i=0;i<arr.length;i++)
   {
      if(arr.A[i]-i!=diff)
      {
         cout<<"Missing Element is :"<<diff+i<<endl;
         diff++;
      }
   }
}

int main()
{
 struct Array arr1={{1,2,3,4,5,7,8,9,10},10,9};   //array starting from 1
 Missing1(arr1);

 struct Array arr2={{7,8,9,10,12,13,14,16,17},10,9}; //array not starting from 1 and has multiple missing elements
 Missing_n(arr2);

 return 0;
}
