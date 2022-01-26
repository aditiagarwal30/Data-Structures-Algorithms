#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;
void Create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;
 
 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}

struct Node * LSearch( struct Node *p, int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
           return p;
        p=p->next;   
    }
    return NULL;
}

int main()
{
    int A[]={3,4,1,6,8,4,9,32,12,56};
    Create(A,10);
    struct Node *temp;
    temp= LSearch(first,90);
    if(temp)
    {
        printf("key is found %d", temp->data);
    }
    else
    {
        printf("key not found");
    }
    return 0;
}
