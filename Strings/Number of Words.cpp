#include <stdio.h>

int main()
{   int words=1;
	char s[]="How are you?";

	for(int i=0;s[i]!='\0';i++)
		if(s[i]==' ' && s[i-1]!=' ')
			words++;
	printf("Number of words: %d\n",words);

	return 0;
}
