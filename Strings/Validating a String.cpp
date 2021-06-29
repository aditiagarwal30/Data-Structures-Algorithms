#include <stdio.h>

int valid(char *id)
{
	for(int i=0; id[i]!='\0';i++)
	{
		if( !(id[i]>=65 && id[i]<=90) && !(id[i]>=97 && id[i]<=122) && !(id[i]>=48 && id[i]<=57))
			return 0;
	}
	return 1;
}

int main()
{   int i;
	char *p="Aditi@2k1";
	char *q="Rishi2003";

	if(valid(p))
		printf("Valid String\n");
	else
		printf("Not Valid\n");


	if(valid(q))
		printf("Valid String\n");
	else
		printf("Not Valid\n");

	return 0;
}
