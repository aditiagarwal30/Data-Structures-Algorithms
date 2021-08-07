//The following example shows the usage of atoi() function:
#include<stdio.h>
#include<stdlib.h>
int main()
{
 char str[10]="12345";
 char str1[10]="12345.57";
 char str2[10]="12345a678";
 int i=atoi("156");
 int a=atoi(str);
 int b=atoi(str1);
 int d=atoi(str2);
 printf("%d\t",i); //12
 printf("%d\t",a); //12345
 printf("%d\t",b+5); //12350
 printf("%d\t",d); //12345
}
