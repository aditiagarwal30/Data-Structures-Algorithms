#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a[]="verbose";
	char b[]="observe";
	int H[26]={0};
	int i;

	for(i=0;a[i]!='\0';i++)
		H[a[i]-97]++;
	for(i=0;b[i]!='\0';i++)
	{
        H[b[i]-97]--;
        if(H[b[i]-97]<0)
        {
        	printf("NOT ANAGRAM\n");
        	break;
        }
	}
	if(b[i]=='\0')
		printf("ANAGRAM");
	return 0;

}
