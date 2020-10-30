// Array as Abstract Data Type

#include<stdio.h>
#include<stdlib.h>

// creating an abstract array
struct Array
{
    int total_size;
    int used_size;
    int *ptr;
};

// user-define data type
typedef enum
{
    t, f
}boolean;

// Creates a Dynamic Array of tSize
void createArray(struct Array *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize*sizeof(int));

    // Inserting elements
    int index;
    printf("Enter Values in Array\n");
    for (index = 0; index < a->used_size; index++)
    {
        printf("Enter Element %d : ", index + 1);
        scanf("%d", &(a->ptr)[index]);
    }
}

// Inserting Element in Array
void insert(struct Array *a, int loc)
{
    int index;
    if (loc > a->total_size)
        printf("Invalid Location\n");
    else if (a->used_size == a->total_size)
        printf("Array Overflow\n");
    else
    {
        for(index = (a->used_size - 1) ; index >= loc - 1 ; index--)
            (a->ptr)[index + 1] = (a->ptr)[index];
        printf("Enter Element : ");
        scanf("%d", &(a->ptr)[loc - 1]);
        a->used_size++;
        printf("Element Inserted Successfully\n");
    }
}

// Deleting Element from Array
void delete(struct Array *a, int loc)
{
    int index;
    if (loc > a->total_size)
        printf("Invalid Location\n");
    else if (a->used_size == 0)
        printf("Array Underflow\n");
    else
    {
        for(index = loc - 1 ; index < a->used_size - 1 ; index++)
            (a->ptr)[index] = (a->ptr)[index + 1];
        a->used_size--;
        printf("Element Deleted Successfully\n");
    }
}

// Displaying Elements of Array
void displayArray(struct Array *a)
{
    int index;
    if(a->used_size == 0)
        printf("Array Underflow");
    else
    {
        printf("\nEntered Values are as follows\n");
        for (index = 0; index < a->used_size; index++)
        {
            printf("Element %d : %d\n", index + 1, (a->ptr)[index]);
        }
    }
}

int main()
{
    int n, choice, loc;
    boolean exit_flag = f;
    printf("Enter Size of Array : ");
    scanf("%d", &n);

    struct Array arr;
    createArray(&arr, n * 2, n);

    while(exit_flag != t)
    {
        printf("\nEnter\n");
        printf("1. To Insert an Element\n");
        printf("2. To Delete an Elemrnt\n");
        printf("3. To Display Array\n");
        printf("0. To Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0 : exit_flag = t; break;
            case 1 :
            {
                printf("\nEnter Location where you want to Insert Element : ");
                scanf("%d", &loc);
                insert(&arr, loc);
                break;
            }
            case 2 :
            {
                printf("\nEnter Location where you want to Delete Element from : ");
                scanf("%d", &loc);
                delete(&arr, loc);
                break;
            }
            case 3 : displayArray(&arr); break;
            default : printf("\nInvald Choice, Try Again\n");
        }
    }
    return 0;
}