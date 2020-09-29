#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50

char stack[max];
int top = -1;

void precedenceChecker(char);
void push(char);
void pop(int);

// driver function
void main(){
	char strng[max];
	int index;
	
	printf("Enter Infix String : ");
	gets(strng);
	
	printf("Postfix String : ");
	
	push('(');
	strng[strlen(strng)] = ')';
	
	for(index = 0; index < strlen(strng); index++){
		if(strng[index] == '(')
			push(strng[index]);
		else if((strng[index] >= 'a' && strng[index] <= 'z') || (strng[index] >= 'A' && strng[index] <= 'Z'))
			printf("%c", strng[index]);
		else if((strng[index] == ')'))
			pop(index);
		else
			precedenceChecker(strng[index]);		
	}
	
	getch();
}

// function to push value in stack
void push(char opr){
	stack[++top] = opr;
}

// function to check operator precedence
void precedenceChecker(char opr){
	if(opr == '/' || opr == '*' || opr == '%')
		if(stack[top] == '+' || stack[top] == '-' || stack[top] == '(')
			push(opr);
		else
			printf("%c", opr);
	else
		if(stack[top] == '/' || stack[top] == '*' || stack[top] == '%')
			printf("%c", stack[top--]);
		else if(stack[top] == '(')
			push(opr);
		else
			printf("%c", opr);
			
}

// function to pop values after closing bracket
void pop(int curr_index){
	int index;
	for (index = curr_index; index > -1; index--){
		if (stack[top] == '('){
			top--;
			break;
		}
		else
			printf("%c", stack[top--]);
	}
}
