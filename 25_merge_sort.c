#include<stdio.h>

// Function to Sort Array using Merge Sort Algorithm
void merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Function to Merge Sub-Arrays into Final Sorted Array
void merge(int arr[], int low, int mid, int high)
{
    int sorted_array[10];
    int left_index, right_index, final_index, index;
    left_index = final_index = low;
    right_index = mid + 1;

    while(left_index <= mid && right_index <= high)
        if(arr[left_index] < arr[right_index])
            sorted_array[final_index++] = arr[left_index++];
        else
            sorted_array[final_index++] = arr[right_index++];

    while(left_index <= mid)
        sorted_array[final_index++] = arr[left_index++];
    
    while(right_index <= high)
        sorted_array[final_index++] = arr[right_index++];

    for (index = low; index <= high; index++)
        arr[index] = sorted_array[index];
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

    merge_sort(arr, 0, n - 1);

    printf("\nSorted Array\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : %d\n", index + 1, arr[index]);
    }
    return 0;
}