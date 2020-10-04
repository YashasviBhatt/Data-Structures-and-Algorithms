#include<stdio.h>
#include<conio.h>

void main(){
	int num_of_lines, star, space;						// declaring int type variables
	
	// taking input for number of lines from user
	printf("Enter Number of Lines : ");
	scanf("%d", &num_of_lines);
	
	// printing pattern
	for(space = num_of_lines - 1; space >= 0; space--){						// loop to add spaces in the line
		for(star = num_of_lines - space; star > 0; star--){					// loop to print * in the line
			printf("*");
		}
		printf("\n");														// for next line
	}
	
	getch();
}
