#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void createLinkedList(int);
void displayLinkedList();
void insertNodeStart(int);
void insertNodeEnd(int);
void insertNodeMid(int, int, int);
void deleteNodeStart();
void deleteNodeEnd(int);
void deleteNodeMid(int, int);

int num_of_nodes;

// structure to create node for linked list
struct node{
	struct node *addr_prev;
	int data;
	struct node *addr_next;
}*start, *end;

typedef enum{
	t, f
}boolean;

// driver function
void main(){
	int choice;
	int position, data;
	boolean not_exit = t;
	
	// taking input for number of nodes by user
	printf("Enter Value for Number of Nodes to Create : ");
	scanf("%d", &num_of_nodes);
	
	createLinkedList(num_of_nodes);	 // calling function to create Linked List
	
	while(not_exit == t){
		
		// for further operation
		printf("\nEnter :\n");
		printf("1. To Display Linked List\n");
		printf("2. To Insert a Node at Start\n");
		printf("3. To Insert a Node at End\n");
		printf("4. To Insert a Node at a position\n");
		printf("5. To Delete a Node from Start\n");
		printf("6. To Delete a Node from End\n");
		printf("7. To Delete a Node from a position\n");
		printf("0. To Exit\n");
		printf("Enter Your Choice : ");
		scanf("%d", &choice);
		
		// creating switch-case to reflect user's choice
		switch(choice){
			case 0 : not_exit = f; break;
			case 1 : displayLinkedList(); break;
			case 2 : {
				printf("\nEnter Value to Insert : ");
				scanf("%d", &data);
				insertNodeStart(data);
			} break;
			case 3 : {
				printf("\nEnter Value to Insert : ");
				scanf("%d", &data);
				insertNodeEnd(data);
			} break;
			case 4 : {
				printf("\nEnter Value to Insert : ");
				scanf("%d", &data);
				printf("Enter Position where you want to insert Value : ");
				scanf("%d", &position);
				insertNodeMid(data, position, num_of_nodes);
			} break;
			case 5 : {
				deleteNodeStart();
			} break;
			case 6 : {
				deleteNodeEnd(num_of_nodes);
			} break;
			case 7 : {
				printf("\nEnter Position from where you want to Delete : ");
				scanf("%d", &position);
				deleteNodeMid(position, num_of_nodes);
			} break;
			default : printf("\nWrong Choice, Please Try Again");
		}
	}
}

// function for node creation
void createLinkedList(int num){
	int data, node_index;
	struct node *pri_ptr, *sec_ptr;
	
	// creating starting node
	start = (struct node *)malloc(sizeof(struct node));		// allocating memory
	printf("Enter Node Value : ");
	scanf("%d", &data);
	// inserting value
	start->data = data;
	start->addr_next = NULL;
	start->addr_prev = NULL;
	
	sec_ptr = start;
	
	for (node_index = 1; node_index < num; node_index++){
		// creating next node
		pri_ptr = (struct node *)malloc(sizeof(struct node));	// memory allocation
		printf("Enter Node Value : ");
		scanf("%d", &data);
		// inserting values
		pri_ptr->data = data;
		pri_ptr->addr_next = NULL;
		pri_ptr->addr_prev = sec_ptr;
		// connecting nodes
		sec_ptr->addr_next = pri_ptr;
		sec_ptr = sec_ptr->addr_next;
	}
	end = pri_ptr;
}

// function to display Linked List
void displayLinkedList(){
	struct node *pri_ptr;
	pri_ptr = start;
	while(pri_ptr != NULL){
		printf("%d ", pri_ptr->data);
		pri_ptr = pri_ptr->addr_next;
	}
	printf("\n");
}

//function to insert node at start
void insertNodeStart(int val){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));			// memory allocation
	ptr->data = val;
	ptr->addr_next = start;
	ptr->addr_prev = NULL;
	start->addr_prev = ptr;
	start = ptr;
	num_of_nodes += 1;
}

//function to insert node at end
void insertNodeEnd(int val){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));			// memory allocation
	end->addr_next = ptr;
	ptr->data = val;
	ptr->addr_next = NULL;
	ptr->addr_prev = end;
	end = ptr;
	num_of_nodes += 1;
}

// function to insert node at a certain location
void insertNodeMid(int val, int pos, int len){
	int node_index;
	struct node *pri_ptr, *sec_ptr;
	pri_ptr = start;
	for(node_index = 0; node_index < len; node_index++){
		if((node_index == (pos - 1)) && ((node_index > 0) && (node_index < (len - 1)))){
			struct node *ptr;
			ptr = (struct node *)malloc(sizeof(struct node));			// memory allocation
			ptr->data = val;
			ptr->addr_prev = sec_ptr;
			sec_ptr->addr_next = ptr;
			ptr->addr_next = pri_ptr;
			pri_ptr->addr_prev = ptr;
			break;
		}
		else{
			sec_ptr = pri_ptr;
			pri_ptr = pri_ptr->addr_next;
		}
	}
	num_of_nodes += 1;
}

// function to delete node from start
void deleteNodeStart(){
	struct node *ptr;
	ptr = start;
	start=start->addr_next;
	start->addr_prev = NULL;
	ptr->addr_next = NULL;
	free(ptr);
}

// function to delete node from end
void deleteNodeEnd(int len){
	struct node *pri_ptr,*sec_ptr;
	pri_ptr = start;
	sec_ptr = start;
	while(pri_ptr->addr_next != NULL){
		sec_ptr = pri_ptr;
		pri_ptr = pri_ptr->addr_next;
	}
	sec_ptr->addr_next = NULL;
	pri_ptr->addr_prev = NULL;
	free(pri_ptr);
	end = sec_ptr;
}

// function to delete node from a certain position
void deleteNodeMid(int pos, int len){
	int node_index;
	struct node *pri_ptr, *sec_ptr, *ptr;
	pri_ptr = start;
	for(node_index = 0; node_index < len; node_index++){
		if((node_index == (pos - 1)) && ((node_index > 0) && (node_index < len - 1))){
			sec_ptr->addr_next = pri_ptr->addr_next;
			ptr = pri_ptr->addr_next;
			ptr->addr_prev = sec_ptr;
			pri_ptr->addr_next = NULL;
			pri_ptr->addr_prev = NULL;
			break;
		}
		else{
			sec_ptr = pri_ptr;
			pri_ptr = pri_ptr->addr_next;
		}
	}
}
