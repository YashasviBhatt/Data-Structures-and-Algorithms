#include<stdio.h>
#include<stdlib.h>

// Node Definition
struct Node
{
    int data;
    struct Node *addr_next;
}*start;

// Function to create Linked List
int createLinkedList(int n)
{
    int index = 1;

    if(n == 0)
    {
        printf("Invalid Input\n");
        return 1;
    }

    struct Node *pri_ptr, *sec_ptr;
    start = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Nodes Data\n");
    printf("Enter Node %d Data : ", index);
    scanf("%d", &start->data);
    start->addr_next = NULL;

    sec_ptr = start;

    while(index != n)
    {
        pri_ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter Node %d Data : ", index + 1);
        scanf("%d", &pri_ptr->data);
        pri_ptr->addr_next = NULL;
        sec_ptr->addr_next = pri_ptr;
        sec_ptr = sec_ptr->addr_next;
        index++;
    }
}

// Function to Insert Node at the Starting of the Linked List
int insertStart(int n)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));

    if(n == 0)
        ptr->addr_next = NULL;
    else
        ptr->addr_next = start;
    
    printf("\nEnter Node Data : ");
    scanf("%d", &ptr->data);
    printf("Node Added Successfully\n");

    start = ptr;

    return ++n;
}

// Function to Insert Node in the Mid of the Linked List
int insertMid(int n)
{
    int loc, index = 1;

    printf("\nEnter Location : ");
    scanf("%d", &loc);

    if((loc > (n + 1)) || (loc < 1))
    {
        printf("Invalid Location\n");
        return n;
    }

    if(loc == 1)
        return insertStart(n);
    else if(loc == (n + 1))
        return insertEnd(n);

    struct Node *ptr, *pri_ptr, *sec_ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Node Data : ");
    scanf("%d", &ptr->data);

    sec_ptr = start;
    pri_ptr = sec_ptr->addr_next;

    while(index < (loc - 1))
    {
        sec_ptr = pri_ptr;
        pri_ptr = pri_ptr->addr_next;
        index++;
    }

    sec_ptr->addr_next = ptr;
    ptr->addr_next = pri_ptr;

    printf("Node Added Successfully\n");

    return ++n;
}

// Function to Insert Node at the End of the Linked List
int insertEnd(int n)
{
    struct Node *ptr, *pri_ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->addr_next = NULL;

    printf("\nEnter Node Data : ");
    scanf("%d", &ptr->data);
    printf("Node Added Successfully\n");
    
    if(n == 0)
    {
        start = ptr;
        return ++n;
    }

    pri_ptr = start;

    while(pri_ptr->addr_next != NULL)
        pri_ptr = pri_ptr->addr_next;
    
    pri_ptr->addr_next = ptr;

    return ++n;
}

// Function to Delete Node from Start
int deleteStart(int n)
{
    if(n == 0)
    {
        printf("\nLinked List Underflow");
        return 0;
    }
    else if(n == 1)
    {
        free(start);
        printf("\nNode Removed Successfully\n");
        return 0;
    }
    struct Node *ptr;
    ptr = start;
    start = start->addr_next;
    free(ptr);
    printf("\nNode Removed Successfully\n");
    return --n;
}

// Function to Delete Node from End
int deleteEnd(int n)
{
    if(n == 0)
    {
        printf("\nLinked List Underflow");
        return 0;
    }
    else if(n == 1)
    {
        free(start);
        printf("\nNode Removed Successfully\n");
        return 0;
    }

    struct Node *pri_ptr, *sec_ptr;
    sec_ptr = start;
    pri_ptr = sec_ptr->addr_next;

    while(pri_ptr->addr_next != NULL)
    {
        sec_ptr = pri_ptr;
        pri_ptr = pri_ptr->addr_next;
    }
    sec_ptr->addr_next = NULL;
    free(pri_ptr);
    printf("\nNode Removed Successfully\n");
    return --n;
}

// Function to Delete Node from Mid
int deleteMid(int n)
{
    int loc, index = 1;
    if(n == 0)
    {
        printf("\nLinked List Underflow");
        return 0;
    }

    printf("\nEnter Location : ");
    scanf("%d", &loc);

    if((loc > n) || (loc < 1))
    {
        printf("Invalid Location\n");
        return n;
    }

    if(loc == 1)
        return deleteStart(n);
    else if(loc == n)
        return deleteEnd(n);
    
    struct Node *pri_ptr, *sec_ptr;
    sec_ptr = start;
    pri_ptr = sec_ptr->addr_next;

    while(index < (loc - 1))
    {
        sec_ptr = pri_ptr;
        pri_ptr = pri_ptr->addr_next;
        index++;
    }
    sec_ptr->addr_next = pri_ptr->addr_next;
    free(pri_ptr);
    printf("Node Removed Successfully\n");
    return --n;
}

// Function to Display Linked List
int display(int n)
{
    int index = 1;

    if(n == 0)
    {
        printf("\nLinked List Underflow\n");
        return 1;
    }

    printf("\nEntered Data\n");
    struct Node *ptr = start;
    while(ptr != NULL)
    {
        printf("Node %d Data : %d\n", index, ptr->data);
        ptr = ptr->addr_next;
        index++;
    }
    
    return 0;
}

int main()
{
    int num_of_nodes, choice, exit_flag = 0;

    printf("Enter Number of Nodes : ");
    scanf("%d", &num_of_nodes);

    createLinkedList(num_of_nodes);

    while(1)
    {
        printf("\nEnter\n");
        printf("1. To Insert a Node at STARTING of Linked List\n");
        printf("2. To Insert a Node at END of Linked List\n");
        printf("3. To Insert a Node Somewhere At MID of Linked List\n");
        printf("4. To Delete a Node from STARTING of Linked List\n");
        printf("5. To Delete a Node from END of Linked List\n");
        printf("6. To Delete a Node from Somewhere At MID of Linked List\n");
        printf("7. To Display\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0 : return 0;
            case 1 : num_of_nodes = insertStart(num_of_nodes); break;
            case 2 : num_of_nodes = insertEnd(num_of_nodes); break;
            case 3 : num_of_nodes = insertMid(num_of_nodes); break;
            case 4 : num_of_nodes = deleteStart(num_of_nodes); break;
            case 5 : num_of_nodes = deleteEnd(num_of_nodes); break;
            case 6 : num_of_nodes = deleteMid(num_of_nodes); break;
            case 7 : display(num_of_nodes);
        }
    }
}