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

struct node * merge(struct node * first, struct node *second)
{
    struct node *third=0, *last=0;
    if(first->data < second->data)
    {
        third=last=first;
        first=first->next;
        last->next=NULL;
    }
    else
    {
        third=last=second;
        second=second->next;
        last->next=NULL;
    }
    while( first && second)
    {
        if(first->data < second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first!=NULL)
    {
        while(first)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
    }
    else
    {
        while(second)
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    return third;
}

int main()
{
    head=insert(head);
    head2=insert(head2);
    display(head);
    display(head2);
    head=merge(head, head2);
    display(head);
}
           