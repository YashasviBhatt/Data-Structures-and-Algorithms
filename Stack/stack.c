#include<stdio.h>
#include<conio.h>

#define MAX 10

void push(int);
void pop();
void peek();
void diplay();

int stack[MAX];
int top = -1;

typedef enum{
	t, f
}boolean;

void main(){
	int choice, item;
	boolean not_exit = t;
	
	while (not_exit == t){
		printf("\n\nEnter\n");
		printf("1. To Push\n");
		printf("2. To Pop\n");
		printf("3. To Peek\n");
		printf("4. To Display Stack\n");
		printf("0. To Exit\n");
		printf("Enter Your choice : ");
		scanf("%d", &choice);
	
		switch(choice){
			case 0 : not_exit = f; break;
			case 1 : {
				printf("\nEnter Item to Push : ");
				scanf("%d", &item);
				push(item);
			} break;
			case 2 : pop(); break;
			case 3 : peek(); break;
			case 4 : display(); break;
			default : printf("\nWrong Choice, Please Try Again");
		}
	}
}

// function to push value in stack
void push(int item){
	if (top == (MAX - 1))
		printf("Stack Overflow");
	else
		stack[++top] = item;
}

// function to pop value from stack
void pop(){
	if (top == -1)
		printf("Stack Underflow");
	else
		printf("Popped Item : %d", stack[top--]);
}

// function to peek the top most item
void peek(){
	if (top == -1)
		printf("Stack Underflow");
	else
		printf("Top-Most Item : %d", stack[top]);
}

// function to display stack
void display(){
	int index;
	printf("Stack : ");
	if (top == -1)
		printf("Stack Underflow");
	else{
		for (index = 0; index <= top; index++)
			printf("%d ", stack[index]);
	}
}
