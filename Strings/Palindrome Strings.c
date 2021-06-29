#include<stdio.h>

int main()
{
	char a[]="madam";
	int i,j;

	for(i=0;a[i]!='\0';i++);
	j=i-1;
	int c=0;        // length of string

	for(i=0;i<=j;i++,j--)
	{
		if(a[i]!=a[j])
		{
			printf("Not a Palindrome\n");
			c=1;
			break;
		}
	}
	if(c==0)
	printf("Palindrome\n");

    return 0;
}
