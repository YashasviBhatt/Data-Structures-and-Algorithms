#include<stdio.h>
#include<stdlib.h>

int sort(int arr[], int n, int max){
    static int count[10], sorted_array[50]; 
    int index;

    for(index = 0; index < n; index++)
        count[arr[index]]++;
    
    for(index = 1 ; index <= max ; index++)
        count[index] += count[index - 1];

    for(index = (n - 1) ; index >= 0 ; index--)
        sorted_array[--count[arr[index]]] = arr[index];

    return sorted_array;
}

int binarySearch(int arr[], int l, int h, int e)
{
    int mid = (l + h) / 2;
    if(arr[mid] == e)
        return mid + 1;
    else if(l >= h)
        return 32767;
    else if(e > arr[mid])
        binarySearch(arr, mid + 1, h, e);
    else
        binarySearch(arr, l, mid - 1, e);
}

int main()
{
    int arr[50], *sorted_array;
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

    sorted_array = sort(arr, num_of_elmnt, 9);

    printf("Enter Number you want to Search : ");
    scanf("%d", &srch_elmnt);

    status = binarySearch(sorted_array, 0, num_of_elmnt - 1, srch_elmnt);
    
    if(status != 32767)
        printf("\nElement Found at Location %d\n", status);
    else
        printf("\nNot Found\n");

    printf("\nArray\n");
    for(index = 0 ; index < num_of_elmnt ; index++)
        printf("Element %d : %d\n", index + 1, sorted_array[index]);
    
    return 0;
}