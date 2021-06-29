#include <stdio.h>

int main()
{   int i;
	char s[]={'w','e','l','c','o','m','e','\0'};
	char *p="Aditi Agarwal";

	for(i=0;s[i]!='\0';i++);
    printf("Length of %s is %d\n",s,i);

    for(i=0;p[i]!='\0';i++);
    printf("Length of %s is %d",p,i);

return 0;
}
