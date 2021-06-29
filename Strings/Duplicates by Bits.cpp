#include <stdio.h>
int main()
{
	char a[]="blindingly";
	int H=0,x=0;

	for(int i=0;a[i]!='\0';i++)
	{
		x=1;
		x=x<<(a[i]-97);
		if((x & H)>0)
            printf("%c is Duplicate\n",a[i]);
        else
			H=H|x;
	}
	return 0;
}
