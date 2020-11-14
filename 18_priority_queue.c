#include<stdio.h>

// Item Definition
struct Item
{
    int data;
    int priority;
    struct Item *addr_next;
}*left, *right;

// Function to Enqueue Item into the Queue
void enqueue()
{
    struct Item *ptr;
    ptr = (struct Item *)malloc(sizeof(struct Item));
    printf("\nEnter Item : ");
    scanf("%d", &ptr->data);
    printf("Enter Priority : ");
    scanf("%d", &ptr->priority);

    if(left == NULL)
    {
        ptr->addr_next = NULL;
        left = right = ptr;
    }
    else if(ptr->priority > right->priority)
    {
        right->addr_next = ptr;
        ptr->addr_next = NULL;
        right = ptr;
    }
    else if(ptr->priority < left->priority)
    {
        ptr->addr_next = left;
        left = ptr;
    }
    else
    {
        struct Item *pri_ptr, *sec_ptr;
        sec_ptr = left;
        pri_ptr = sec_ptr->addr_next;
        while(pri_ptr != right->addr_next)
        {
            if((ptr->priority > sec_ptr->priority) && (ptr->priority <= pri_ptr->priority))
            {
                sec_ptr->addr_next = ptr;
                ptr->addr_next = pri_ptr;
                return;
            }
            else
            {
                sec_ptr = pri_ptr;
                pri_ptr = pri_ptr->addr_next;
            }
        }
    }

    printf("Item Enqueued Successfully\n\n");
}

// Function to Dequeue Item from Queue
void dequeue()
{
    if(left == NULL)
    {
        printf("\nQueue Underflow\n\n");
        return;
    }
    else if(left == right)
    {
        free(left);
        left = right = NULL;
    }
    else
    {
        struct Item *pri_ptr, *sec_ptr;
        sec_ptr = left;
        pri_ptr = sec_ptr->addr_next;
        while(pri_ptr != right)
        {
            sec_ptr = pri_ptr;
            pri_ptr = pri_ptr->addr_next;
        }
        sec_ptr->addr_next = NULL;
        free(pri_ptr);
        right = sec_ptr;
    }
    printf("\nItem Dequeued Successfully\n\n");
}

// Function to peek into the Stack
void peek()
{
    if (left == NULL)
        printf("\nQueue Underflow\n\n");
    else
        printf("\nElement with Highest Priority\nValue : %d\nPriority : %d\n\n", right->data, right->priority);
}

int main()
{
    int choice;
    left = NULL;
    right = NULL;

    while(1)
    {
        printf("Enter\n");
        printf("1. To Enqueue Item\n");
        printf("2. To Dequeue Item\n");
        printf("3. To Peek into Queue\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0 : return 0;
            case 1 : enqueue(); break;
            case 2 : dequeue(); break;
            case 3 : peek(); break;
            default : printf("\nInvalid Choice, Try Again\n\n");
        }
    }
}