#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} nodetype;

nodetype *enq(nodetype *, int);
nodetype *deq(nodetype *);
void display(nodetype *);

int main()
{
    nodetype *f = NULL, *r = NULL;
    int ch, num, x;

    while (1)
    {
        printf("Press 1 to Enqueue \n Press 2 to Dequeue \n Press 3 to display\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value to enqueue \n");
            scanf("%d", &num);
            r = enq(r, num);
            if (f == NULL)
                f = r;
            break;

        case 2:
            f = deq(f);
            break;

        case 3:
            display(f);
            break;

        default:
            printf("Invalid choice");
        }
        printf("Press 1 to continue and 0 to exit \n");
        scanf("%d", &x);
        if (x != 1)
            break;
    } //while
    return 0;
}
nodetype *enq(nodetype *r, int n)
{
    nodetype *p = NULL;
    p = (nodetype *)malloc(sizeof(nodetype));
    if (p == NULL)
        printf("Underflow");
    else
    {
        p->info = n;
        p->next = r;
        r = p;
    }
    return r;
}

nodetype *deq(nodetype *f)
{
    if (f == NULL)
        printf("Queue is empty");
    else
    {
        nodetype *temp = NULL;
        temp = f;
        printf("Element dequeued is %d", f->info);
        f = f->next;
        free(temp);
    }
    return f;
}

void display(nodetype *f)
{
    if (f == NULL)
        printf("Queue is empty");
    else
    {

        while (f != NULL)
        {
            printf("%d \n", f->info);
            f = f->next;
        }
    }
}