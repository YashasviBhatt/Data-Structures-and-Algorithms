#include<stdio.h>
#define MAX 50
int QUEUE[MAX];
int front, rear;
front = -1, rear = -1;

// Function to Enqueue Item
void enqueue()
{
    int item;
    if (((front == 0) && (rear == (MAX - 1))) || (front == (rear + 1)))
        printf("\nQueue Overflow\n\n");
    else
    {
        if (rear == -1)
            front = rear = 0;
        else if (rear == (MAX - 1))
            rear = 0;
        else
            rear++;
        printf("\nEnter Element : ");
        scanf("%d", &item);
        QUEUE[rear] = item;
        printf("Element Enqueued Successfully\n\n");
    }
}

// Function to Dequeue
void dequeue()
{
    if (front == -1)
        printf("\nQueue Underflow\n\n");
    else
    {
        printf("\nDequeued Item : %d", QUEUE[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == (MAX - 1))
            front = 0;
        else
            front++;
        
        printf("\nElement Dequeued Successfully\n\n");
    }
}

// Function to Peek into Queue
void peek()
{
    if (front == -1)
        printf("\nQueue Underflow\n\n");
    else
        printf("\nLast Element in Queue : %d\n\n", QUEUE[front]);
}

/*
// Function to Display Queue
void display()
{
    int index, index1 = 1;
    printf("\nEntered Element\n");
    for(index = front ; index <= rear ; index++)
        printf("Element %d : %d\n", index1++, QUEUE[index]);
    printf("\n");
}
*/

int main()
{
    int choice;

    while(1)
    {
        printf("Enter\n");
        printf("1. To Enqueue an Element\n");
        printf("2. To Dequeue an Element\n");
        printf("3. To Peek into the Queue\n");
        // printf("4. Display Queue\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 0 : return 0;
            case 1 : enqueue(); break;
            case 2 : dequeue(); break;
            case 3 : peek(); break;
            // case 4 : display(); break;
            default : printf("\nInvalid Choice, Try Again\n\n");
        }
    }
    return 0;
}