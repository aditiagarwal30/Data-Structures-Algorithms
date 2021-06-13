#include<stdio.h>

int sum(int n)        //by recursion
{
 if(n==0)
 return 0;
 return  sum(n-1)+n;
}
int Isum(int n)       // iterative sum of n natural numbers
{
 int s=0,i;
 for(i=1;i<=n;i++)
 s=s+i;
 return s;
}

int main()
{
 int r=sum(5);
 printf("%d ",r);
 return 0;
}
