#include <stdio.h>

int main()
{
	char p[]="python";
	char q[]="pytHon";

	int i,j;
	for(i=0,j=0;p[i]!='\0' && q[j]!='\0';i++,j++)
	{
		if(p[i]!=q[j])
			break;
	}

	if(p[i]==q[j])
		printf("Strings are Equal\n");
	else if(p[i]<q[j])
		printf("String q is smaller\n");
	else
		printf("String p is smaller\n");

	return 0;
}
