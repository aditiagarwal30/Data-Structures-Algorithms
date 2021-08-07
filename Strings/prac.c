#include <stdio.h>
int main()
{
char months [12][25] =
{"January","February","March","April","May","June","July","August",
"September","October","November", "December"} ;
char *dow[] =
 {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

printf("Months of a Year\n") ;
for (int i = 0; i < 12; i++)
    printf("%s\n", months[i]);

printf("Days of the Week\n") ;
for (int i = 0; i < 7; i++)
    printf("%s\n", dow[i]);
return 0;
}
