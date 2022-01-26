#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int info;
    struct node *next;
} nodetype;

void push(nodetype**, int);
void pop(nodetype**);
void disp(nodetype*);

int main()
{
    nodetype *p = NULL, *top = NULL;
    int n, ch, x;

    while (1)
    {
        printf("Press: \n 1 to push \n 2 to pop \n 3 to display \n 4 to exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value you want to push \n");
            scanf("%d", &n);
             push(&top, n);
            break;

        case 2:
             pop(&top);
            break;

        case 3:
            disp(top);
            break;

        default:
            printf("Invalid choice");
        }

        printf("Press 1 to continue and 0 to exit \n");
        scanf("%d", &x);
        if (x != 1)
            break;
    }
    return 0;
}

void push(nodetype **tp, int n)
{
    nodetype *p = NULL;
    p = (nodetype *)malloc(sizeof(nodetype));

    if (p == NULL)
        printf(" Not enough memory");
    else
    {

        p->info = n;
        p->next = *tp;
        *tp = p;
    }
}

void pop(nodetype **tp)
{
    if (*tp == NULL)
        printf("Stack is empty");
    else
    {
        nodetype *temp;
        temp = *tp;
        printf("Element popped is %d \n",( *tp)->info);
        *tp = (*tp)->next;
        free(temp);
    }
}

void disp(nodetype *tp)
{
    if (tp == NULL)
        printf("Empty");
    else
    {
        while (tp != NULL)
        {
            printf("%d", (tp)->info);
            tp = tp->next;
        }
    }
}