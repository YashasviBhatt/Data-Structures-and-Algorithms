#include<stdio.h>

int insertElement(int arr[], int n, int loc)
{
    int index;
    if((loc > (n + 1)) || (loc <= 0))
        printf("Invalid Location\n");
    else if(n == 50)
        printf("Array Overflow\n");
    else
    {
        for(index = n - 1 ; index >= loc - 1 ; index--)
            arr[index + 1] = arr[index];
        printf("Enter Element : ");
        scanf("%d", &arr[loc - 1]);
        printf("Element Inserted Successfully\n");
        n++;
    }
    return n;
}

int deleteElement(int arr[], int n, int loc)
{
    int index;
    if((loc > n) || (loc <= 0)) 
        printf("Invalid Location\n");
    else if(n == 0)
        printf("Array Underflow\n");
    else
    {
        for(index = loc - 1 ; index < n - 1 ; index++)
            arr[index] = arr[index + 1];
        printf("Element Deleted Successfully\n");
        n--;
    }
    return n;
}

void display(int arr[], int n)
{
    int index;
    if(n == 0)
        printf("Array Underflow\n");
    else
    {
        printf("\nEntered Elements\n");
        for(index = 0 ; index < n ; index++)
            printf("Element %d : %d\n", index + 1, arr[index]);
    }
}

int main()
{
    int arr[50];
    int num_of_elmnt, loc;
    
    int choice, index;
    int exit = 1;

    printf("Enter Number of Elements : ");
    scanf("%d", &num_of_elmnt);

    if(num_of_elmnt > 50)
    {
        printf("Invalid Option");
        return 1;
    }

    printf("\nEnter Elements\n");
    for(index = 0 ; index < num_of_elmnt ; index++)
    {
        printf("Element %d : ", index + 1);
        scanf("%d", &arr[index]);
    }

    while(exit != 0)
    {
        printf("\nEnter\n");
        printf("1. To Insert an Element\n");
        printf("2. To Delete an Element\n");
        printf("3. To Display Array\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0 : return 0;
            case 1 :
            {
                printf("\nEnter Location where you want to Insert Element : ");
                scanf("%d", &loc);
                num_of_elmnt = insertElement(arr, num_of_elmnt, loc);
                break;
            }
            case 2 :
            {
                printf("\nEnter Location where you want to Delete Element From : ");
                scanf("%d", &loc);
                num_of_elmnt = deleteElement(arr, num_of_elmnt, loc);
                break;
            }
            case 3 : display(arr, num_of_elmnt); break;
            default : printf("\nInvalid Choice, Please Try Again\n");
        }
    }
    return 0;
}