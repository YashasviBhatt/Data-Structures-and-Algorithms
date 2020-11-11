#include<stdio.h>

struct Node
{
    int data;
    struct Node *addr_next
}*top;

// Function to Push Element into Stack
struct Node * push()
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Data : ");
    scanf("%d", &ptr->data);
    if (top == NULL)
    {
        top = ptr;
        top->addr_next = NULL;
    }
    else
    {
        ptr->addr_next = top;
        top = ptr;
    }
    printf("Item Pushed Successfully\n\n");
    return top;
}

struct Node * pop()
{
    if (top == NULL)
    {
        printf("\nStack Underflow\n\n");
        return NULL;
    }
    else if (top->addr_next == NULL)
    {
        printf("\nPopped Item : %d\n", top->data);
        printf("Item Popped Successfully\n\n");
        free(top);
        return NULL;
    }
    else
    {
        struct Node *ptr;
        ptr = top;
        top = top->addr_next;
        printf("\nPopped Item : %d\n", ptr->data);
        printf("Item Popped Successfully\n\n");
        free(ptr);
        return top;
    }
}

struct Node * peek()
{
    if (top == NULL)
        printf("\nStack Underflow\n\n");
    else
        printf("\nTop-Most Item : %d\n\n", top->data);
}

int main()
{
    int choice;
    top = NULL;

    while(1)
    {
        printf("Enter\n");
        printf("1. To Push an Element\n");
        printf("2. To Pop an Element\n");
        printf("3. To Peek into the Stack\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0 : return 0;
            case 1 : top = push(); break;
            case 2 : top = pop(); break;
            case 3 : peek(); break;
            default : printf("\nInvalid Choice, Try Again\n\n");
        }
    } 
}