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
    cout<<"LL created \n";
}

int Max_Element(struct node* tp)
{
    int max=-32768;
    while(tp!=NULL)
    {
        if(tp->data>max)
        {
            max=tp->data;
        }
        tp=tp->next;
    }
    return max;
    
}

int main()
{
    int a[]={10,2,13,41,5,6,7};
    Create(a,7);
    cout<<"Max element: "<<Max_Element(first);
}






