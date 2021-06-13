#include<stdio.h>

int factorial(int n)
{
	if(n>0)
		return factorial(n-1)*n;
	else if (n==0)
		return 1;
}

int main()
{
	int s=factorial(6);
	printf("%d",s);
	return 0;
}
