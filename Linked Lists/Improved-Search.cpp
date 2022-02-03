#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
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
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
struct Node * improved_Search(struct Node *p, int key)
{
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return 1;
            
        }
        q=p;
        p=p->next;
    }
   return 0;
}
int main()
{
 struct Node *temp=NULL;
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);
 temp=improved_Search(first, 32);
 printf("%d status\n",temp);
 Display(first);
 return 0;
}
