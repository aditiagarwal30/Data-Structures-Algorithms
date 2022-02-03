#include<iostream>  
#include<stdlib.h>  
using namespace std;

struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head, *head2;  

void insert(struct node *first)
{
    int n;
    cout<<"no. of elements \n";
    cin>>n;
    while(n--)
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
            if(first == NULL)  
            {  
                ptr -> next = NULL;  
                first = ptr;  
                printf("\nNode inserted\n");  
            }  
            else  
            {  
                temp = first;  
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

void concatenate(struct node * first, struct node *second)
{
    struct node *p=first;
    while(p->next)
    {
        p=p->next;
    }
    p->next=second;
    free(second);
}

int main()
{
    insert(head);
    insert(head2);
    display(head);
    display(head2);
    concatenate(head, head2);
    display(head);
}
           