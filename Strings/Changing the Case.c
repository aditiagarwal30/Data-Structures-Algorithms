#include <stdio.h>

int main()
{   int i;
	char s[]={'w','e','l','c','o','m','e','\0'};
	char *p="ADITI AGARWAL";
	char *m="Rishi Agarwal";

	for(i=0;s[i]!='\0';i++)
	{
		s[i]=s[i]-32;
	}
    printf("%s\n",s);

    for(int i=0;p[i]!='\0';i++)
    {
    	p[i]=p[i]+32;
    }
    puts(p);

    for (int i=0;m[i]!='\0';i++)
    {
    	if(m[i]>=65 && m[i]<=90)
    		m[i]=m[i]+32;
    	else if(m[i]>=97 && m[i]<=122)
    		m[i]=m[i]-32;
    	else
    		continue;
    }
    puts(m);

return 0;
}
