#include<stdio.h>

// Function to Sort Array using Gnome Sort
void gnome_sort(int arr[], int n)
{
    int pos = 0, temp;
    while(pos < n)
        if ((pos == 0) || (arr[pos] >= arr[pos - 1]))
            pos++;
        else
        {
            temp = arr[pos];
            arr[pos] = arr[pos - 1];
            arr[pos - 1] = temp;
            pos--;
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

    gnome_sort(arr, n);

    printf("\nSorted Array\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : %d\n", index + 1, arr[index]);
    }
    return 0;
}