#include<stdio.h>

// Function to Sort Array using Bubble Sort Algorithm
void bubble_sort(int arr[], int n)
{
    int index1, index2, temp;
    for(index1 = 0 ; index1 < n - 1 ; index1++)
        for(index2 = 0 ; index2 < n - index1 - 1 ; index2++)
            if(arr[index2] > arr[index2 + 1])
            {
                temp = arr[index2];
                arr[index2] = arr[index2 + 1];
                arr[index2 + 1] = temp;
            }
}

int main()
{
    int arr[10];
    int n, index;

    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    if(n > 10 || n < -1)
    {
        printf("Invalid Input");
        return 0;
    }

    printf("Enter Elements\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : ", index + 1);
        scanf("%d", &arr[index]);
    }

    bubble_sort(arr, n);

    printf("\nSorted Array\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : %d\n", index + 1, arr[index]);
    }
    return 0;
}