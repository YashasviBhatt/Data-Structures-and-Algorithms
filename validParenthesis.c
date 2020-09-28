#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50

int top = -1;
int stack[max];

void push(char);
char pop(char);

// driver function
void main(){
	char strng[max];
	int index, flag;
	printf("Enter a String : ");
	gets(strng);
	
	for(index = 0 ; index < strlen(strng) ; index ++){
		if(strng[index] == '(' || strng[index] == '{' || strng[index] == '[')
			push(strng[index]);
		else if(strng[index] == ')' || strng[index] == '}' || strng[index] == ']'){
			flag = pop(strng[index]);
			if (flag == 0){
				printf("Invalid String");
				exit(0);
				// printf("This Statement is still running");
			}
		}
	}
	if(top >= 0)
		printf("Invalid String");
	else
		printf("Valid String");
		
	getch();
}

// function to push value in stack
void push(char par){
	stack[++top] = par;
}

// function to pop value from stack as well as verifying the string
char pop(char par){
	if (top == -1)
		return 0;
	else{
		if((par == ')') && (stack[top] == '(')){
			top--;
			return 1;
		}
		else if ((par == '}') && (stack[top] == '{')){
			top--;
			return 1;
		}
		else if ((par == ']') && (stack[top] == '[')){
			top--;
			return 1;
		}
		else
			return 0;
	}
}
