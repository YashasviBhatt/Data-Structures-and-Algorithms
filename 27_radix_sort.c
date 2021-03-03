#include<stdio.h>

// Base Function of Count Sort
void count_sort(int arr[], int n, int exp)
{
    int output[n], index;
    int count[10] = { 0 };

    for (index = 0 ; index < n ; index++)
        count[(arr[index] / exp) % 10]++;

    for (index = 1 ; index < 10 ; index++)
        count[index] += count[index - 1];
    
    for (index = n - 1 ; index >= 0 ; index--)
        output[--count[(arr[index] / exp) % 10]] = arr[index];

    for (index = 0 ; index < n ; index++)
        arr[index] = output[index];
}

// Function to Sort Array using Radix Sort Algorithm
void radix_sort(int arr[], int n, int max)
{
    int exp;
    for(exp = 1 ; max / exp > 0 ; exp *= 10)
        count_sort(arr, n, exp);
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

    radix_sort(arr, n, max);

    printf("\nSorted Array\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : %d\n", index + 1, arr[index]);
    }

    return 0;
}