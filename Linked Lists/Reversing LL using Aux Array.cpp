#include<iostream>  
#include<stdlib.h>  
using namespace std;

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
            printf("\nNode inserted\n");  
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
            printf("\nNode inserted \n");  
          
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
        while (ptr)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}   

void rev_ll()
{
    int A[100],i=0;
    struct node *p=head;
    
    while(p)
    {
        A[i]=p->data;
        i++;
        p=p->next;
    }
    p=head;
    i--;
    while(p)
    {
        p->data=A[i];
        i--;
        p=p->next;
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
    rev_ll();
    display();
}
           