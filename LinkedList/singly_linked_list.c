// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Singly Linked List //
#include<stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list *next;   
};
struct list *start=NULL, *node, *curr;
void insertAtBeginning()
{
    int val;
    printf("\nEnter value: ");
    scanf("%d", &val);
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->data = val;
    ptr->next = start;
    start = ptr;
    printf("\nUpdated Linked List is\n");
    curr = start;
    while (curr!=NULL)
    {
        printf("%d=>",curr->data);
        curr = curr->next;
    }
}
void insertAtMiddle()
{
    int location, val;
    printf("\nEnter the location of new node: ");
    scanf("%d", &location);
    printf("\nEnter value: ");
    scanf("%d", &val);
    struct list *ptr, *temp;
    ptr = (struct list *)malloc(sizeof(struct list));
    ptr->data = val;
    temp = start;
    for(int i=0; i<location; i++)
    {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    printf("\nUpdated Linked List is\n");
    curr = start;
    while (curr!=NULL)
    {
        printf("%d=>",curr->data);
        curr = curr->next;
    }
}
void insertAtEnd()
{
    int val;
    printf("\nEnter value: ");
    scanf("%d", &val);
    struct list *ptr, *temp;
    ptr = (struct list *)malloc(sizeof(struct list));
    ptr->data = val;
    ptr->next = NULL;
    temp = start;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    printf("\nUpdated Linked List is\n");
    curr = start;
    while (curr!=NULL)
    {
        printf("%d=>",curr->data);
        curr = curr->next;
    }
}
void deleteAtBeginning()
{
    struct list *ptr;
    ptr = start;
    start = ptr->next;
    free(ptr);
    printf("\nUpdated Linked List is\n");
    curr = start;
    while (curr!=NULL)
    {
        printf("%d=>",curr->data);
        curr = curr->next;
    }
}
void deleteAtMiddle()
{
    int location;
    printf("\nEnter the location to delete: ");
    scanf("%d", &location);
    struct list *ptr, *ptr2;
    ptr = start;
    for(int i=0; i<location; i++)
    {
        ptr2 = ptr;
        ptr = ptr->next;
    }
    ptr2->next = ptr->next;
    free(ptr);
    printf("\nUpdated Linked List is\n");
    curr = start;
    while (curr!=NULL)
    {
        printf("%d=>",curr->data);
        curr = curr->next;
    }
}
void deleteAtEnd()
{
    struct list *ptr, *ptr2;
    ptr = start;
    while (ptr->next!=NULL)
    {
        ptr2 = ptr;
        ptr = ptr->next;
    }
    ptr2->next = NULL;
    free(ptr);
    printf("\nUpdated Linked List is\n");
    curr = start;
    while (curr!=NULL)
    {
        printf("%d=>",curr->data);
        curr = curr->next;
    }
}
int main()
{
    int val=0;
    do
    {
        printf("*** Singly Linked List ***");
        printf("\nEnter a value (0 to stop): ");
        scanf("%d", &val);
        if(val!=0)
        {
            node = (struct list *)malloc(sizeof(struct list));
            node->data = val;
            node->next = NULL;
            if(start==NULL)
            {
                start = node;
            }
            else
            {
                curr->next = node;
            }
            curr = node;
        } 
    } while (val!=0);
    curr = start;
    printf("Linked List is\n");
    while (curr!=NULL)
    {
        printf("%d=>",curr->data);
        curr = curr->next;
    }
    int choice = 0;
    do
    {
        printf("\n\n*** MENU ***");
        printf("\n*Insert Node at beginning (1)");
        printf("\n*Insert Node at midddle (2)");
        printf("\n*Insert Node at end (3)");
        printf("\n*Delete Node at beginning (4)");
        printf("\n*Delete Node at midddle (5)");
        printf("\n*Delete Node at end (6)");
        printf("\nEnter input (0 to stop): ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtMiddle();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtMiddle();
            break;
        case 6:
            deleteAtEnd();
            break;
        default:
            break;
        }
    } while (choice!=0);

    return 0;
}

