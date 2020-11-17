#include<stdio.h>

// Function to Sort Array using Shell Sort Algorithm
void shell_sort(int arr[], int n)
{
    int index1, temp, gap = n / 2;
    while(gap > 0)
    {
        for(index1 = 0 ; index1 < (n - gap) ; index1++)
            if(arr[index1] > arr[index1 + gap])
            {
                temp = arr[index1];
                arr[index1] = arr[index1 + gap];
                arr[index1 + gap] = temp;
            }
        gap /= 2;
    }
}

int main()
{
    int arr[10];
    int n, index;

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
    }

    shell_sort(arr, n);

    printf("\nSorted Array\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : %d\n", index + 1, arr[index]);
    }
    return 0;
}