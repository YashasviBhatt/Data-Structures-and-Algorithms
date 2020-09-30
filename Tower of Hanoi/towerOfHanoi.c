#include<stdio.h>
#include<conio.h>

void TowerOfHanoi(int, char, char, char);
static int num_of_steps = 0;

// driver function
void main() {
	int n;
	printf("Enter Number of Disks : ");
	scanf("%d", &n);						// Number of disks 
	TowerOfHanoi(n, 'A', 'C', 'B'); 		// A, B and C are names of towers
	
	printf("\n\nTotal Steps : %d", num_of_steps);
	
	getch();
}

// Tower of Hanoi Implementation Function 
void TowerOfHanoi(int num_of_disks, char sourceTower, char destinationTower, char auxiliaryTower) {
	num_of_steps++;
	if (num_of_disks == 1) {
		printf("\nMoving Disk %d from Tower %c to Tower %c", num_of_disks, sourceTower, destinationTower);
		return;
	} 
	TowerOfHanoi(num_of_disks - 1, sourceTower, auxiliaryTower, destinationTower);
	printf("\nMoving Disk %d from Tower %c to Tower %c", num_of_disks, sourceTower, destinationTower);
	TowerOfHanoi(num_of_disks - 1, auxiliaryTower, destinationTower, sourceTower);
}
