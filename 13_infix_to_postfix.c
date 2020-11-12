#include<stdio.h>
#include<string.h>
#define MAX 50

char stack[MAX];
int top = -1;
char final_string[MAX];

// Function to check Operator Precedence
void precedenceChecker(char opr)
{
	if(opr == '/' || opr == '*' || opr == '%')
		if(stack[top] == '+' || stack[top] == '-' || stack[top] == '(')
			push(opr);
		else
		{
			final_string[strlen(final_string)] = stack[top--];
			stack[++top] = opr;
		}
	else
		if(stack[top] == '/' || stack[top] == '*' || stack[top] == '%')
		{
			pop(top);
			stack[++top] = opr;
		}
		else if(stack[top] == '(')
			push(opr);
		else
		{
			final_string[strlen(final_string)] = stack[top--];
			stack[++top] = opr;
		}	
}

// Function to Push into the Stack
void push(char opr)
{
	stack[++top] = opr;
}

// Function to Pop from Stack
void pop(int curr_index)
{
	int index;
	for (index = curr_index; index > -1; index--)
	{
		if (stack[top] == '(')
		{
			top--;
			break;
		}
		else
			final_string[strlen(final_string)] = stack[top--];
	}
}

int main()
{
	char strng[MAX];
	int index;
	
	printf("Enter Infix String : ");
	gets(strng);
	
	printf("Postfix String : ");
	
	push('(');
	strng[strlen(strng)] = ')';
	
	for(index = 0; index < strlen(strng); index++)
	{
		if(strng[index] == '(')
			push(strng[index]);
		else if((strng[index] >= 'a' && strng[index] <= 'z') || (strng[index] >= 'A' && strng[index] <= 'Z'))
			final_string[strlen(final_string)] = strng[index];
		else if((strng[index] == ')'))
			pop(index);
		else
			precedenceChecker(strng[index]);		
	}
	
	puts(final_string);

	return 0;
}