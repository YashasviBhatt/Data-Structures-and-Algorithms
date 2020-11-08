#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int n, int e)
{
    int index;
    for(index = 0 ; index < n ; index++)
        if(arr[index] == e)
            return index + 1;    
    return 32767;
}

int main()
{
    int arr[50];
    int num_of_elmnt, index;
    int srch_elmnt;
    int status;

    printf("Enter Number of Elements : ");
    scanf("%d", &num_of_elmnt);

    if((num_of_elmnt < 0) || (num_of_elmnt > 50))
    {
        printf("Invalid Input");
        return 1;
    }

    for(index = 0 ; index < num_of_elmnt ; index++)
        arr[index] = rand() % 10;

    printf("Enter Number you want to Search : ");
    scanf("%d", &srch_elmnt);

    status = linearSearch(arr, num_of_elmnt, srch_elmnt);

    if(status != 32767)
        printf("\nElement Found at Location %d\n", status);
    else
        printf("\nNot Found\n");

    printf("\nArray\n");
    for(index = 0 ; index < num_of_elmnt ; index++)
        printf("Element %d : %d\n", index + 1, arr[index]);

    return 0;
}