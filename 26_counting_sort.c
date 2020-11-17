#include<stdio.h>

// Function to Sort Array using Counting Sort Algorithm
void counting_sort(int arr[], int n, int max)
{
    static int count[11], sorted_array[10];
    int index, value;
    for(index = 0 ; index < n ; index++)
        count[arr[index]]++;
    
    for(index = 1 ; index < n ; index++)
        count[index] += count[index - 1];

    for(index = (n - 1) ; index >= 0 ; index--)
        sorted_array[--count[arr[index]]] = arr[index];

    for(index = 0 ; index < n ; index++)
        arr[index] = sorted_array[index];
}

int main()
{
    int arr[10];
    int n, index, max = 0;

    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    if(n > 10 || n < 0)
    {
        printf("Invalid Input");
        return 0;
    }

    printf("Enter Elements\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : ", index + 1);
        scanf("%d", &arr[index]);
        if(max < arr[index])
            max = arr[index];
    }

    counting_sort(arr, n, max);

    printf("\nSorted Array\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : %d\n", index + 1, arr[index]);
    }
    return 0;
}