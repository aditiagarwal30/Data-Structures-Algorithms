#include<iostream>  
#include<stdlib.h>  
using namespace std;

struct node   
{  
    int data;  
    struct node *next;   
}*head=NULL, *head2=NULL;  

struct node * insert(struct node *l1)
{
    struct node *tmp,*q;
    int n,m,i;
    printf("nodes number: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter data: ");
        scanf("%d",&m);
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data=m;
        tmp->next=NULL;
        if(l1==NULL)
        {
            l1=tmp;
        }
        else
        {
            q=l1;
            while(q->next!=NULL)
                {
                    q=q->next;
                }
            q->next=tmp;
        }
    }
    return l1;
}



void display(struct node* front)  
{  
    struct node *ptr;  
    ptr = front;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}   

struct node * concatenate(struct node * first, struct node *second)
{
    struct node *p=first;
    while(p->next)
    {
        p=p->next;
    }
    p->next=second;
    return first;
}

int main()
{
    head=insert(head);
    head2=insert(head2);
    display(head);
    display(head2);
    head=concatenate(head, head2);
    display(head);
}
           