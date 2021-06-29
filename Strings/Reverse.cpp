#include <stdio.h>

int main()
{
	char *p="python";
	char q[7];
	int i,j;
	for(i=0;p[i]!='\0';i++);  // for counting the length
	for(j=0;p[j]!='\0';j++,i--)
	    q[j]=p[i-1];

	 printf("%s",q);
}
