#include<stdio.h>
#define MAX 50

int QUEUE[MAX];
int front, rear;
front = -1, rear = -1;

// Function to Implement Input-Restricted Queue
int input_restricted()
{
    int choice;
    while(1)
    {
        printf("\nEnter\n");
        printf("1. To Enqueue an Element\n");
        printf("2. To Dequeue Element from Front\n");
        printf("3. To Dequeue Element from Rear\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0 : return 0;
            case 1 : enqueue_rear(); break;
            case 2 : dequeue_front(); break;
            case 3 : dequeue_rear(); break;
            default : printf("\nInvalid Choice, Try Again\n\n");
        }
    }
}

// Function to Implement Output-Restricted Queue
int output_restricted()
{
    int choice;
    while(1)
    {
        printf("\nEnter\n");
        printf("1. To Enqueue an Element from Rear\n");
        printf("2. To Enqueue an Element from Front\n");
        printf("3. To Dequeue Element\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0 : return 0;
            case 1 : enqueue_rear(); break;
            case 2 : enqueue_front(); break;
            case 3 : dequeue_front(); break;
            default : printf("\nInvalid Choice, Try Again\n\n");
        }
    }
}

// Function to Enqueue Element from Rear
void enqueue_rear()
{
    int item;
    if ((front == 0 && rear == (MAX - 1)) || (rear == (front - 1)))
        printf("\nQueue Overflow\n");
    else
    {
        if(rear == -1)
            front = rear = 0;
        else if (rear == (MAX - 1))
            rear = 0;
        else
            rear++;
        
        printf("\nEnter Element : ");
        scanf("%d", &item);
        QUEUE[rear] = item;
        printf("Element Enqueued Successfully\n");
    }
}

// Function to Enqueue Element from Front
void enqueue_front()
{
    int item;
    if ((front == 0 && rear == (MAX - 1)) || (rear == (front - 1)))
        printf("\nQueue Overflow\n");
    else
    {
        if(rear == -1)
            front = rear = 0;
        else if (front == 0)
            front = MAX - 1;
        else
            front--;

        printf("\nEnter Element : ");
        scanf("%d", &item);
        QUEUE[rear] = item;
        printf("Element Enqueued Successfully\n");
    }
}

// Function to Dequeue Element from Front
void dequeue_front()
{
    if (front == -1)
        printf("\nQueue Underflow\n");
    else
    {
        printf("\nDequeued Item : %d", QUEUE[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == (MAX - 1))
            front = 0;
        else
            front++;
        
        printf("\nElement Dequeued Successfully\n");
    }
}

// Function to Dequeue Element from Rear
void dequeue_rear()
{
    if (front == -1)
        printf("\nQueue Underflow\n");
    else
    {
        printf("\nDequeued Item : %d", QUEUE[rear]);
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
        
        printf("\nElement Dequeued Successfully\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("Enter\n");
        printf("1. To use Input-Restricted Double-Ended Queue\n");
        printf("2. To use Output-Restricted Double-Ended Queue\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 0 : return 0;
            case 1 : input_restricted(); break;
            case 2 : output_restricted(); break;
            default : printf("\nInvalid Choice, Try Again\n\n");
        }
    }
    return 0;
}