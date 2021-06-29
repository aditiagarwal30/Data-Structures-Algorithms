#include <stdio.h>

int main()
{
	char p[]="python";

	int i,j;
	for(i=0;p[i]!='\0';i++);  // for counting the length

	i=i-1;
	for(j=0;j<i;j++,i--)
	    {
	    	int temp= p[j];
	    	p[j]=p[i];
	    	p[i]=temp;
	    }

	 printf("%s",p);
}
