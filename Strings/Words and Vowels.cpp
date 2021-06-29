#include <stdio.h>

int main()
{   int i;
	char s[]={'w','e','l','c','o','m','e','\0'};
	char *p="ADITI AGARWAL";
	char *m="Rishi Agarwal";

	int vcount=0, ccount=0;

	for(int i=0;s[i]!='\0';i++)
	{
		switch(s[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			    vcount++;
			    break;
			default:
			    ccount++;

		}
	}
	printf("String : %s\nVowels: %d\nConsonants: %d\n",s,vcount,ccount);

vcount=0;
ccount=0;
for(int i=0;p[i]!='\0';i++)
	{
		switch(p[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			    vcount++;
			    break;
			default:
			    ccount++;

		}
	}
	printf("String : %s\nVowels: %d\nConsonants: %d\n",p,vcount,ccount);

vcount=0;
ccount=0;
for(int i=0;m[i]!='\0';i++)
	{
		switch(m[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			    vcount++;
			    break;
			default:
			    ccount++;

		}
	}
	printf("String : %s\nVowels: %d\nConsonants: %d\n",m,vcount,ccount);


return 0;
}


