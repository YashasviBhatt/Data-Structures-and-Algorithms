#include<stdio.h>
#include<string.h>
#define MAX 30
char STACK[MAX];

// Function to Push into the Stack
int push(char par, int top)
{
    STACK[++top] = par;
    return top;
}

// Function to Pop from the Stack
int pop(char par, int top)
{
    if (par == ')' && STACK[top] == '(')
        return --top;
    else if (par == '}' && STACK[top] == '{')
        return --top;
    else if (par == ']' && STACK[top] == '[')
        return --top;
    else
    {
        printf("Invalid String");
        exit(0);
    }
}

int main()
{
    char expr[MAX];
    int index, len, top = -1;
    
    printf("Enter Expression : ");
    gets(expr);
    len = strlen(expr);

    if(len > MAX)
    {
        printf("String too large for this Program");
        exit(0);
    }

    for(index = 0 ; index < len ; index++)
        if(expr[index] == '(' || expr[index] == '{' || expr[index] == '[')
            top = push(expr[index], top);
        else if(expr[index] == ')' || expr[index] == '}' || expr[index] == ']')
            top = pop(expr[index], top);

    if (top != -1)
        printf("Invalid String");
    else
        printf("Valid String");
    
    return 0;
}