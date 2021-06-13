#include <stdio.h>

//By Iterative calls

double e(int x, int n)
{
 double s=1;
 int i;
 double num=1;
 double den=1;
 for(i=1;i<=n;i++)
 {
 num*=x;
 den*=i;
 s+=num/den;
 }
 return s;
}

int main()
{
 printf("%lf \n",e(1,10));
 return 0;
}

/*
Taylor Series Horner’s Rule (By Recursion)

double e(int x, int n)
{
 static double s;
 if(n==0)
 return s;
 s=1+x*s/n;
 return e(x,n-1);
}
int main()
{
 printf("%lf \n",e(2,10));
 return 0;
}
*/
