#include<stdio.h>

// Function to Sort Array using Quick Sort Algorithm
void quick_sort(int arr[], int low, int high)
{
    int pi;
    
    if(low < high)
    {
        pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Function to Partition
int partition(int arr[], int low, int high)
{
    int left = low + 1;
    int right = high;
    int temp;

    do
    {
        while(arr[left] <= arr[low])
            left++;
            
        while(arr[right] > arr[low])
            right--;
            
        if(left < right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }while(left < right);

    temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;

    return right;
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

    quick_sort(arr, 0, n - 1);

    printf("\nSorted Array\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : %d\n", index + 1, arr[index]);
    }
    return 0;
}