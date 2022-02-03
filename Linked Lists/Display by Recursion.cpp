#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL;

void Create(int A[], int n)
{
    int i;
    struct node *last, *t;
    first=(struct node*)malloc(sizeof(struct node ));
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t= new (struct node);
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display_recursive(struct node* tp)
{
    if(tp!=NULL)
    {
        cout<<tp->data<<endl;
        Display_recursive(tp->next);
    }
    
}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    Create(a,7);
    Display_recursive(first);
}






