#include<stdio.h>
#include<stdlib.h>

// Node Definition
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}*root;

// Function to Insert Node in Binary Search Tree
void insert_node(struct Node *root_node, struct Node *ptr)
{
    if(root_node->data > ptr->data)
        if(root_node->left == NULL)
            root_node->left = ptr;
        else
            insert_node(root_node->left, ptr);
    else
        if(root_node->right == NULL)
            root_node->right = ptr;
        else
            insert_node(root_node->right, ptr);
}

// Function to Delete Node in Binary Search Tree
struct Node * delete_node(struct Node *root_node, int key)
{
    if(root_node == NULL)
        return root_node;

    if(root_node->data > key)
        root_node->left = delete_node(root_node->left, key);
    else if(root_node->data < key)
        root_node->right = delete_node(root_node->right, key);
    else
    {
        if(root_node->right == NULL)
        {
            struct Node *new_root;
            new_root = root_node->left;
            free(root_node);
            return new_root;
        }
        else if(root_node->left == NULL)
        {
            struct Node *new_root;
            new_root = root_node->right;
            free(root_node);
            return new_root;
        }
        else
        {
            struct Node *new_root;
            new_root = root_node->right;
            while(new_root && new_root->left)
                new_root = new_root->left;
            root_node->data = new_root->data;
            delete_node(root_node, new_root->data);
        }
    }
    return root_node;
}

// Function for Pre-Order Traversal of Binary Search Tree
void preorder_traversal(struct Node *root_node)
{
    if(root_node != NULL)
    {
        printf("%d ", root_node->data);
        preorder_traversal(root_node->left);
        preorder_traversal(root_node->right);
    }
}

// Function for In-Order Traversal of Binary Search Tree
void inorder_traversal(struct Node *root_node)
{
    if(root_node != NULL)
    {
        inorder_traversal(root_node->left);
        printf("%d ", root_node->data);
        inorder_traversal(root_node->right);
    }
}

// Function for Post-Order Traversal of Binary Search Tree
void postorder_traversal(struct Node *root_node)
{
    if(root_node != NULL)
    {
        postorder_traversal(root_node->left);
        postorder_traversal(root_node->right);
        printf("%d ", root_node->data);
    }
}

// Function to search for a Node in Binary Search Tree
int search(struct Node *root_node, int key)
{
    if(root_node->data == key)
    {
        printf("Found\n");
        return 1;
    }
    else
    {
        if(root_node->data > key)
            if(root_node->left != NULL)
                search(root_node->left, key);
            else
                return 0;
        else
            if(root_node->right != NULL)
                search(root_node->right, key);
            else
                return 0;
    }
}

int main()
{
    int choice, key, status;

    root = (struct Node *)malloc(sizeof(struct Node));
    root->left = NULL;
    root->right = NULL;
    printf("Enter Root Node Value : ");
    scanf("%d", &root->data);

    while(1)
    {
        printf("\nEnter\n");
        printf("1. To Insert a Node\n");
        printf("2. To Delete Node\n");
        printf("3. For Pre-Order Traversal\n");
        printf("4. For In-Order Traversal\n");
        printf("5. For Post-Order Traversal\n");
        printf("6. To Search for a Node\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0 : return 0;
            case 1 :
            {
                struct Node *ptr;
                ptr = (struct Node *)malloc(sizeof(struct Node));
                printf("\nEnter Node Value : ");
                scanf("%d", &ptr->data);
                ptr->left = NULL;
                ptr->right = NULL;
                insert_node(root, ptr);
                printf("Node Added Successfully\n");
                break;
            }
            case 2 :
            {
                printf("\nEnter Node Value : ");
                scanf("%d", &key);
                struct Node *ptr = delete_node(root, key);
                if(ptr == NULL)
                    printf("\nNode Not Found\n");
                else
                    printf("\nNode Deleted Successfully\n");
                break;
            }
            case 3 :
            {
                printf("\nPre-Order Traversal\n");
                preorder_traversal(root);
                printf("\n");
                break;
            }
            case 4 :
            {
                printf("\nIn-Order Traversal\n");
                inorder_traversal(root);
                printf("\n");
                break;
            }
            case 5 :
            {
                printf("\nPost-Order Traversal\n");
                postorder_traversal(root);
                printf("\n");
                break;
            }
            case 6 :
            {
                printf("\nEnter Node Value : ");
                scanf("%d", &key);
                status = search(root, key);
                if(status == 0)
                    printf("Not Found\n");
                break;
            }
            default : printf("\nInvalid Choice, Please try Again\n");
        }
    }
}