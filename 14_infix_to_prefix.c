#include<stdio.h>
#include<conio.h>
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
			stack[++top] = '(';
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
	for (index = curr_index; index >= 0; index--)
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

// Function to Reverse String
void reverseString(char strng[MAX])
{
	char strng1[MAX];
	int index = 0;
	for(index = strlen(strng) - 1; index >= 0; index--)
	{
		if(strng[index] == '(')
			strng1[(strlen(strng) - 1) - index] = ')';
		else if(strng[index] == ')')
			strng1[(strlen(strng) - 1) - index] = '(';
		else
			strng1[(strlen(strng) - 1) - index] = strng[index];
	}
	strcpy(strng, strng1);
}

int main()
{
	char strng[MAX];
	int index;
	
	printf("Enter Infix String : ");
	gets(strng);
	
	printf("Prefix String : ");
	
	reverseString(strng);
	
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
	
	reverseString(final_string);
	puts(final_string);

	return 0;
}