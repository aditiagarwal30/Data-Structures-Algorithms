// COMPARISON METHOD

#include <iostream>
using namespace std;

int main()
{
	char a[]="aditiagarwal";
	int i,c;
	for(i=0;a[i]!='\0';i++)
	{
		c=1;
		if(a[i]!='0')
		for(int j=i+1;a[j]!='\0';j++)
		    if(a[i]==a[j])
				{
					c++;
					a[j]='0';
				}
		if(c>1)
		cout<<"Duplicate "<<a[i]<<" with frequency : "<<c<<endl;
    }

    return 0;
}
