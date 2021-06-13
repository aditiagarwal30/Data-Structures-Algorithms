#include "stdio.h"

void fib(int n){
	int a=0,b=1,sum=1;

    printf("%d \n",sum);   //prints first term

	for (int i=2; i<=n; i++)
	{
		sum=a+b;
		printf("%d\n", sum);
		a=b;
		b=sum;
	}
}

int fib_recursion(int n)  //will return the nth term of fibonacci series
{
	if (n==1 || n==0)
		return n;
	return fib_recursion(n-2)+fib_recursion(n-1);
}

//Fiboacci by Excessive Recursion--- MEMOIZATION

int F[20];

int fib_memoization(int n)
{
    if(n<=1)
    {
    	F[n]=n;
    	return n;
    }
    else
    {
    	if(F[n-2]==-1)
    		F[n-2]=fib_memoization(n-2);
    	if(F[n-1]==-1)
    		F[n-2]=fib_memoization(n-1);
        F[n]=F[n-2]+F[n-1];
    	return F[n-2]+F[n-1];
    }

}

int main()

{

	for(int i=0;i<20;i++)
		F[i]=-1 ;   //initializing the array with a non-fibonacci term

	fib(7);
	printf("By Recursion: %d \n",fib_recursion(7));
	printf("By Memoization: %d \n",fib_memoization(7));
}
