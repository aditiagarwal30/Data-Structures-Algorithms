#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  

void insert()
{
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}

void Sorted()
{
    struct node *ptr=NULL, *temp=NULL, *p=NULL;
    int x;
    ptr= (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("overflow");
    }
    else
    {
        printf("\nEnter Value ");
        scanf("%d",&x);
        ptr->data=x;
        if(head==NULL)
        {
           ptr->next=NULL;
           head=ptr;
        }
        else
        {
            temp=head;
            while(x>=temp->data && temp->next)
            {
                p=temp;
                temp=temp->next;
            }
            if(temp==head)
            {
                ptr->next=temp;
                head=ptr;
            }
            if(temp->next==NULL)
            {
                temp->next=ptr;
                ptr->next=NULL;
            }
            else
            {
                p->next=ptr;
                ptr->next=temp;
            }
            
            
        }
    }
}
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}     

int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    Sorted();
    display();
}
           