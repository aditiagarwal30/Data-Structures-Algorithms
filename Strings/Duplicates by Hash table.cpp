#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	char a[]="aditiagarwal";
	int max= a[0];

	for(int i=1;a[i]!='\0';i++)
		if(a[i]>max)
			max=a[i];

    int *H=(int *)calloc(max+1-97,sizeof(int));

    for(int i=0;a[i]!='\0';i++)
    	H[a[i]-97]++;
    for(int i=0;i<=max-97;i++)
    	if(H[i]>1)
    		cout<<"Duplicate "<<(char)(i+97)<<" frequency : "<<H[i]<<endl;
    return 0;
}

