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

int Count_Nodes(struct node* tp)
{
    int c=0;
    while(tp!=NULL)
    {
        c++;
        tp=tp->next;
    }
    return c;
    
}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    Create(a,7);
    cout<<"Number of element "<<Count_Nodes(first);
}






