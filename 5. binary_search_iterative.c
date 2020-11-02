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

int binarySearch(int arr[], int n, int e)
{
    int mid, l = 0, h = n - 1;
    while(l <= h)
    {
        mid = (l + h) / 2;
        if(arr[mid] == e)
            return mid + 1;
        else if(e > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return 32767;
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

    status = binarySearch(sorted_array, num_of_elmnt, srch_elmnt);
    
    if(status != 32767)
        printf("\nElement Found at Location %d\n", status);
    else
        printf("\nNot Found\n");

    printf("\nArray\n");
    for(index = 0 ; index < num_of_elmnt ; index++)
        printf("Element %d : %d\n", index + 1, sorted_array[index]);
    
    return 0;
}