#include<stdio.h>
#define MAX 15

int STACK[MAX];

// Function to Push Element into Stack
int push(int top)
{
    if(top == (MAX - 1))
        printf("\nStack Overflow\n\n");
    else
    {
        printf("\nEnter Item : ");
        scanf("%d", &STACK[++top]);
        printf("Item Pushed Successfully\n\n");
    }
    return top;
}

// Function to Pop Element from Stack
int pop(int top)
{
    if(top == -1)
        printf("\nStack Underflow\n\n");
    else
    {
        printf("\nPopped Item : %d\n", STACK[top--]);
        printf("Item Popped Successfully\n\n");
    }
    return top;
}

// Function to Peek into Stack
int peek(int top)
{
    if(top == -1)
        printf("\nStack Underflow\n\n");
    else
        printf("\nTop-Most Item : %d\n\n", STACK[top]);
    return 0;
}

/*
// Function to Display Element of Stack
int display(int top)
{
    int index;
    if(top == -1)
        printf("\nStack Underflow\n\n");
    else
    {
        printf("\nElements\n");
        for(index = 0 ; index < top + 1 ; index++)
            printf("Element %d : %d\n", index + 1, STACK[index]);
        printf("\n");
    }
    return 0;
}
*/

int main()
{
    int choice;
    int top = -1;

    while(1)
    {
        printf("Enter\n");
        printf("1. To Push an Element\n");
        printf("2. To Pop an Element\n");
        printf("3. To Peek into the Stack\n");
        // printf("4. Display Stack\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 0 : return 0;
            case 1 : top = push(top); break;
            case 2 : top = pop(top); break;
            case 3 : peek(top); break;
            // case 4 : display(top); break;
            default : printf("\nInvalid Choice, Try Again\n\n");
        }
    }
    return 0;
}