// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Binary Search Tree //

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

struct node* new_node(int x)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* insert(struct node * root, int x)
{
	if(root==NULL)
		return new_node(x);
	else if(x > root->data)
		root->right = insert(root->right, x);
	else
		root->left = insert(root->left, x);
	return root;
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

struct node* min_value_node(struct node* node)
{
	struct node* current = node;
	while (current && current->left != NULL)
		current = current->left;
 	return current;
}

struct node* delete_node(struct node *root, int data)
{
	if(root==NULL)
		return root;
	if (data < root->data)
        	root->left = delete_node(root->left, data);
        else if (data > root->data)
        	root->right = delete_node(root->right, data); 	
        else
        {
        	if (root->left == NULL) 
        	{
        		struct node* temp = root->right;
            		free(root);
            		return temp;
        	}
        	else if (root->right == NULL) 
        	{
            		struct node* temp = root->left;
            		free(root);
            		return temp;
        	}
        	struct node* temp = min_value_node(root->right);
        	root->data = temp->data;
        	root->right = delete_node(root->right, temp->data);
	}
	return root;
}

void display(struct node *root)
{		
	printf("\nInorder: ");
	inorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\n");
}

int main()
{
	struct node *root;
	int root_data;
	int choice = 0;
	int key;
	printf("*** BINARY SEARCH TREE ***");
	printf("\nEnter root: ");
	scanf("%d", &root_data);
	root = new_node(root_data);
	int input = 0;
	do
	{
		printf("Enter next (0 to stop): ");
		scanf("%d",&input);
		if(input!=0)
		{
			insert(root, input);
		}
	} while (input!=0);
	display(root);
	do
	{
		printf("\n");
		printf("MENU");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n0 to Exit");
		printf("\nEnter Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				do
				{
					printf("Enter data (0 to stop): ");
					scanf("%d",&input);
					if(input!=0)
					{
						insert(root, input);
					}
				} while (input!=0);
				display(root);
				break;
			case 2:
				printf("\nEnter data to delete: ");
				scanf("%d", &key);
				root = delete_node(root, key);
				display(root);
				break;
			default:
				printf("\nInvalid Choice\n");
				break;
		}
	} while (choice!=0);
	return 0;
}
