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

void Delete()
{
    struct node *temp=NULL;
    int pos;
    cout<<"enter the position for deletion\n";
    cin>>pos;
    if(pos==1)
    {
        struct node* p=head;
        head=head->next;
        delete p;
        cout<<"node deleted";
        display();
    }
    else
    {
        temp=head;
        for(int i=1; i<pos-1;i++)
        {
            temp=temp->next;
        }
        struct node* p;
        p=temp->next;
        temp->next=p->next;
        free(p);
        cout<<"node deleted";
        display();
        
    }
    
}

int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    Delete();
}
           