#include <stdio.h>
#include <stdlib.h>

int main()
{
 int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};   //created in stack
 int *B[3];
 int **C;

 int i,j;

 /*----------------------------------------------------------------------*/

 B[0]=(int *)malloc(4*sizeof(int));           //array of array of arrays partially in heap and in stack
 B[1]=(int *)malloc(4*sizeof(int));
 B[2]=(int *)malloc(4*sizeof(int));

/*----------------------------------------------------------------------*/

 C=(int **)malloc(3*sizeof(int *));          //creating array of pointers in heap

 C[0]=(int *)malloc(4*sizeof(int));           //creating arrays to which the pointers will point
 C[1]=(int *)malloc(4*sizeof(int));
 C[2]=(int *)malloc(4*sizeof(int));


 for(i=0;i<3;i++)
 {
     for(j=0;j<4;j++)
         printf("%d ",A[i][j]);
     printf("\n");
 }
 return 0;
}
