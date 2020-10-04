#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void inputRestricted();
void outputRestricted();
void enqueueFront(int);
void enqueueRear(int);
void dequeueFront();
void dequeueRear();
void display();

typedef enum {
	t, f
}boolean;

// driver function
void main(){
	int choice;
	
	printf("Enter\n");
	printf("1. To Perform Input Restricted Queue Operations\n");
	printf("2. To Perform Output Restricted Queue Operations\n");
	printf("0. To Exit\n");
	printf("Enter Your Choice : ");
	scanf("%d", &choice);
	
	switch(choice){
		case 0 : exit(0);
		case 1 : inputRestricted(); break;
		case 2 : outputRestricted(); break;
		default : printf("\nInvalid Choice Entered");
	}
	
	getch();
}

// function to perform Input Restricted Queue Operations
void inputRestricted(){
	int item, choice;
	boolean exit_flag = f;
	
	while(exit_flag == f){
		printf("\nEnter\n");
		printf("1. To Enqueue Element\n");
		printf("2. To Dequeue Element from Front\n");
		printf("3. To Dequeue Element from Right\n");
		printf("4. To Display\n");
		printf("0. To Exit\n");
		printf("Enter Your Choice : ");
		scanf("%d", &choice);
		
		switch(choice){
			case 0 : exit_flag = t; break;
			case 1 : {
				printf("\nEnter Item : ");
				scanf("%d", &item);
				enqueueFront(item);
			} break;
			case 2 : dequeueFront(); break;
			case 3 : dequeueRear(); break;
			case 4 : display(); break;
			default : printf("\nInvalid Choice Entered, Please Try Again");
		}
	}
}

// function to perform Output Restricted Queue Operations
void outputRestricted(){
	int item, choice;
	boolean exit_flag = f;
	
	while(exit_flag == f){
		printf("\nEnter\n");
		printf("1. To Enqueue Element from Front\n");
		printf("2. To Enqueue Element from Rear\n");
		printf("3. To Dequeue Element\n");
		printf("4. To Display\n");
		printf("0. To Exit\n");
		printf("Enter Your Choice : ");
		scanf("%d", &choice);
		
		switch(choice){
			case 0 : exit_flag = t; break;
			case 1 : {
				printf("\nEnter Item : ");
				scanf("%d", &item);
				enqueueFront(item);
			} break;
			case 2 : {
				printf("\nEnter Item : ");
				scanf("%d", &item);
				enqueueRear(item);
			} break;
			case 3 : dequeueRear(); break;
			case 4 : display(); break;
			default : printf("\nInvalid Choice Entered, Please Try Again\n");
		}
	}
}

// function to Enqueue Item from Front
void enqueueFront(int item){
	if((front == 0 && rear == MAX - 1) || (front == rear + 1)){
		printf("\nQueue Overflow\n");
		return;
	}
	else{
		if(front == -1)
			front = rear = 0;
		else if(front == 0)
			front = MAX - 1;
		else
			front--;
		queue[front] = item;
	}
}

// function to Enqueue Item from Rear
void enqueueRear(int item){
	if((front == 0 && rear == MAX - 1) || (rear == front - 1)){
		printf("\nQueue Overflow\n");
		return;
	}
	else{
		if(rear == -1)
			front = rear = 0;
		if(rear == MAX - 1)
			rear = 0;
		else
			rear++;
		queue[rear] = item;
	}
}

// function to Dequeue Item from Front
void dequeueFront(){
	if(front == -1){
		printf("\nQueue Underflow\n");
		return;
	}
	printf("\nDequeued Item : %d\n", queue[front]);
	if(front == rear)
		front = rear = -1;
	else if(front == MAX - 1)
		front = 0;
	else
		front++;
}

// function to Dequeue Item from Rear
void dequeueRear(){
	if(rear == -1){
		printf("\nQueue Underflow\n");
		return;
	}
	printf("\nDequeued Item : %d\n", queue[rear]);
	if(rear == front)
		rear = front = -1;
	else if(rear == 0)
		rear = MAX - 1;
	else
		rear--;
}

// function to Display Queue
void display(){
	int index = front;
	if(front == -1){
		printf("\nQueue Underflow\n");
		return;
	}
	else{
		printf("\n");
		while(index != rear){
			printf("%d ", queue[index]);
			if(index == MAX - 1)
				index = 0;
			else
				index++;
		}
		printf("%d\n", queue[rear]);
	}
}
