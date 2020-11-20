#include<stdio.h>

// Function to Heapify the Array
void heapify(int arr[], int n, int l_idx)
{
    int largest = l_idx;
    int lft = 2 * l_idx + 1;
    int rt = 2 * l_idx + 2;
    int temp;

    // Checking whether left child is greater
    if((lft < n) && (arr[lft] > arr[largest]))
        largest = lft;
    
    // Checking whether right child is greater
    if((rt < n) && arr[rt] > arr[largest])
        largest = rt;
    
    if(largest != l_idx)
    {
        temp = arr[l_idx];
        arr[l_idx] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Function to Sort Array using Heap Sort Algorithm
void heap_sort(int arr[], int n)
{
    int index, temp;

    // Building Max-Heap using Array
    for(index = n/2 - 1 ; index >= 0 ; index--)
        heapify(arr, n, index);
    
    // Sorting using Deletion from Heap Strategy
    for(index = n - 1 ; index > 0 ; index--)
    {
        temp = arr[0];
        arr[0] = arr[index];
        arr[index] = temp;

        heapify(arr, index, 0);
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

    heap_sort(arr, n);

    printf("\nSorted Array\n");
    for(index = 0 ; index < n ; index++)
    {
        printf("Element %d : %d\n", index + 1, arr[index]);
    }
    return 0;
}