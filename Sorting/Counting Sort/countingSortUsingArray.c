#include<stdio.h>
#include<conio.h>
#define MAX 50

int countingSort(int[], int, int);
void display();

// driver function
void main(){
    int num_of_elements, initial_arr[MAX], *final_array;
    int max = 0, index;

    printf("Enter Number of Elements you want to Insert : ");
    scanf("%d", &num_of_elements);

    if(num_of_elements > MAX){
        printf("\nNumber of Items Exceeds the Array Limit");
        return;
    }

    printf("\nInsert Items\n");
    for(index = 0 ; index < num_of_elements ; index++){
        printf("Item %d : ", index);
        scanf("%d", &initial_arr[index]);
        if(initial_arr[index] > max)
            max = initial_arr[index];
    }

    final_array = countingSort(initial_arr, num_of_elements, max);

    printf("Sorted Array : ");
    for(index = 0 ; index < num_of_elements ; index++)
        printf("%d ", final_array[index]);

    getch();
}

// counting sort function
int countingSort(int arr[], int n, int max){
    static int count[MAX], sorted_array[MAX]; 
    int index;

    for(index = 0; index < n; index++)
        count[arr[index]]++;
    
    for(index = 1 ; index <= max ; index++)
        count[index] += count[index - 1];

    for(index = (n - 1) ; index >= 0 ; index--)
        sorted_array[--count[arr[index]]] = arr[index];

    return sorted_array;
}