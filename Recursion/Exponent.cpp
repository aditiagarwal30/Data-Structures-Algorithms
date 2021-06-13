#include<stdio.h>

int exponent(int n,int m)
{
	if(m>0)
		return exponent(n,m-1)*n;
	else if (m==0)
		return 1;
}

int main()
{
	int s=exponent(2,6);
	printf("%d",s);
	return 0;
}