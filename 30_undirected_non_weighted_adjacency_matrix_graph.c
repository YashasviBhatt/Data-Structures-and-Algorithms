#include<stdio.h>
#define MAX 50
#define IGNR -1

// Global Section
int GRAPH[MAX][MAX];
int num_of_nodes;
char node_list[MAX];

// Function to find the Node Value using Linear Search
int node_search(char c)
{
    int idx;
    for(idx = 0 ; idx < num_of_nodes ; idx++)
        if(node_list[idx] == c)
            return idx;
    return -1;
}

// Function to Setup Graph by adding Nodes
void setup_graph(int num_of_nodes)
{
    int ver_idx, hor_idx;

    for(ver_idx = 0 ; ver_idx < MAX ; ver_idx++)
        for(hor_idx = 0 ; hor_idx < MAX ; hor_idx++)
        {    
            GRAPH[ver_idx][hor_idx] = IGNR;
        }

    printf("Enter %d Node Values\n", num_of_nodes);
    for(ver_idx = 0 ; ver_idx < num_of_nodes ; ver_idx++)
    {
        printf("Enter Value of Node %d : ", ver_idx + 1);
        scanf(" %c", &node_list[ver_idx]);
    }

    for(ver_idx = 0 ; ver_idx < num_of_nodes ; ver_idx++)
        for(hor_idx = ver_idx ; hor_idx < num_of_nodes ; hor_idx++)
            GRAPH[ver_idx][hor_idx] = 0;
}

// Function to Insert Edge
void insert_edge()
{
    int src_idx, des_idx;
    char src, des;
    printf("\nEnter Source Node : ");
    scanf(" %c", &src);
    printf("Enter Destination Node : ");
    scanf(" %c", &des);
    src_idx = node_search(src);
    des_idx = node_search(des);
    if(src_idx == -1 || des_idx == -1)
        printf("Either Source Node doesn't Exists or Destination Node doesn't Exists\n\n");
    else
    {
        if(GRAPH[src_idx][des_idx] == 1)
            printf("Edge Already Exists\n\n");
        else
        {
            GRAPH[src_idx][des_idx] = 1;
            printf("Edge Inserted Successfully\n\n");
        }
    }
}

// Function to Delete Edge
void delete_edge()
{
    int src_idx, des_idx;
    char src, des;
    printf("\nEnter Source Node : ");
    scanf(" %c", &src);
    printf("Enter Destination Node : ");
    scanf(" %c", &des);
    src_idx = node_search(src);
    des_idx = node_search(des);
    if(src_idx == -1 || des_idx == -1)
        printf("Either Source Node doesn't Exists or Destination Node doesn't Exists\n\n");
    else
    {
        if(GRAPH[src_idx][des_idx] == 0)
            printf("Edge Doesn't Exists\n\n");
        else
        {
            GRAPH[src_idx][des_idx] = 0;
            printf("Edge Inserted Successfully\n\n");
        }
    }
}

// Function to Insert Node
void insert_node()
{
    char node_val, src;
    int src_idx, des_idx;
    int index;
    if(num_of_nodes != MAX)
    {
        printf("Enter Node Value : ");
        scanf(" %c", &node_val);
        des_idx = node_search(node_val);
        if(des_idx == -1)
        {
            des_idx = num_of_nodes;
            node_list[num_of_nodes++] = node_val;
            for(index = 0 ; index < num_of_nodes ; index++)
                GRAPH[index][des_idx] = 0;
            printf("Add Edge\n");
            printf("Enter Source Node : ");
            scanf(" %c", &src);
            src_idx = node_search(src);
            if(src_idx != -1)
            {
                GRAPH[src_idx][des_idx] = 1;
                printf("Node Added Successfully\n\n");
            }
            else
                printf("Node Not Exists\n\n");
        }
        else
            printf("Node Already Exists\n\n");
    }
    else
        printf("Maximum Node Limit Reached\n\n");
}

// Function to Delete Node
void delete_node()
{
    int node_val, node_index, index;
    int hor_idx, ver_idx;
    if(num_of_nodes != 0)
    {
        printf("Enter the Node Value you want to Delete : ");
        scanf(" %c", &node_val);
        node_index = node_search(node_val);
        if(node_index <= MAX)
        {
            if(node_index != -1)
            {
                for(ver_idx = node_index ; ver_idx < num_of_nodes ; ver_idx++)
                    for(hor_idx = 0 ; hor_idx < num_of_nodes ; hor_idx++)
                        GRAPH[hor_idx][ver_idx] = GRAPH[hor_idx][ver_idx + 1];
                for(hor_idx = node_index ; hor_idx < num_of_nodes ; hor_idx++)
                    for(ver_idx = 0 ; ver_idx < num_of_nodes ; ver_idx++)
                        GRAPH[hor_idx][ver_idx] = GRAPH[hor_idx + 1][ver_idx];
                for(index = node_index ; index < num_of_nodes ; index++)
                    node_list[index] = node_list[index + 1];
                num_of_nodes--;
                printf("Node Deleted Successfully\n\n");
            }
            else
            {
                printf("Node not Exists\n\n");
            }
        }
        else
            printf("Invalid Value Entered\n\n");
    }
    else
        printf("Graph is Empty\n\n");
}

// Function to Display Graph
void display()
{
    int ver_idx, hor_idx, index;
    int no_edge_flag = 0;
    printf("Total Number of Nodes : %d\n", num_of_nodes);
    printf("Nodes : ");
    for(index = 0 ; index < num_of_nodes ; index++)
        printf("%c ", node_list[index]);
    printf("\n\n");
    printf("Edges\n");
    for(ver_idx = 0 ; ver_idx < num_of_nodes ; ver_idx++)
        for(hor_idx = ver_idx ; hor_idx < num_of_nodes ; hor_idx++)
            if(GRAPH[ver_idx][hor_idx] == 1)
            {
                printf("(%c - %c)\n", node_list[ver_idx], node_list[hor_idx]);
                no_edge_flag = 1;
            }
    if(no_edge_flag == 0)
        printf("No Edge Exists\n");
    printf("\n");
}

// Function to Display Adjacency Matrix
void display_matrix()
{
    printf("\n");
    int ver_idx, hor_idx;
    printf("    ");
    for(ver_idx = 0 ; ver_idx < num_of_nodes ; ver_idx++)
        printf("%c ", node_list[ver_idx]);
    printf("\n\n");
    for(ver_idx = 0 ; ver_idx < num_of_nodes ; ver_idx++)
    {
        printf("%c   ", node_list[ver_idx]);
        for(hor_idx = 0 ; hor_idx < num_of_nodes ; hor_idx++)
        {
            if(hor_idx < ver_idx)
                printf("  ");
            else
                printf("%d ", GRAPH[ver_idx][hor_idx]);
        }
        printf("\n");
    }
    printf("\n");
}

// Driver Code
int main()
{
    int choice;
    printf("Enter Number of Nodes to Insert : ");
    scanf("%d", &num_of_nodes);
    if(num_of_nodes <= MAX)
    {
        setup_graph(num_of_nodes);
        printf("Nodes Added Successfully\n\n");
        while(1)
        {
            printf("Enter\n");
            printf("1. To Insert an Edge\n");
            printf("2. To Delete an Edge\n");
            printf("3. To Insert a Node\n");
            printf("4. To Delete a Node\n");
            printf("5. To Display Graph\n");
            printf("6. To Display Adjacency Matrix\n");
            printf("0. To Exit\n");
            printf("\nYour Choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 0 : return 1; break;
                case 1 : insert_edge(); break;
                case 2 : delete_edge(); break;
                case 3 : insert_node(); break;
                case 4 : delete_node(); break;
                case 5 : display(); break;
                case 6 : display_matrix(); break;
                default: printf("\nInvalid Choice, Please Try Again\n\n");
            }
        }
    }
    else
        printf("Maximum 50 Nodes are allowed");
    return 1;
}