#include<stdio.h>
#include<conio.h>
#define max 50

int queue[max];
int front = -1, rear = -1;

void enqueue(int);
void dequeue();
void display();

// enum for user defined variables
typedef enum {
	t, f
}boolean;

// driver function
void main(){
	int choice, item;
	boolean exit_flag = f;
	
	while (exit_flag == f){
		printf("\n\nEnter\n");
		printf("1. To Enqueue\n");
		printf("2. To Dequeue\n");
		printf("3. To Display\n");
		printf("0. To Exit\n");
		printf("Enter Your Choice : ");
		scanf("%d", &choice);

		switch(choice){
			case 0 : exit_flag = t; break;
			case 1 : {
				printf("Enter Item to Insert : ");
				scanf("%d", &item);
				enqueue(item);
			} break;
			case 2 : {
				dequeue();
			} break;
			case 3 : display(); break;
			default : printf("\nInvalid Choice, Please Try Again!");
		}
	}
	
	getch();
}

// function to perform enqueue(inserting an item) operation on queue
void enqueue(item){
	if(rear == max - 1){
		printf("Queue Overflow");
		return;
	}
	else if(front == -1 && rear == -1)
		front = rear = 0;
	else
		rear += 1;
	queue[rear] = item;
}

// function to perform dequeue(removing an item) operation on queue
void dequeue(){
	if((front == -1 && rear == -1) || (front > rear))
		printf("Queue Underflow");
	else
		printf("Dequeued Item : %d", queue[front++]);
}

// function to print queue
void display(){
	int index;
	if((front == -1 && rear == -1) || (front > rear))
		printf("Queue Underflow");
	else
		for(index = front; index <= rear; index++)
			printf("%d ", queue[index]);
}
