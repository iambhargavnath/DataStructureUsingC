// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Doubly Linked List //
#include<stdio.h>
#include<stdlib.h>

struct list
{
    int data;
    struct list *prev;
    struct list *next;
};
struct list *start=NULL, *node, *curr;
void display()
{
    printf("\nLinked List is: \n");
    curr = start;
    while (curr!=NULL)
    {
        printf("%d => ",curr->data);
        curr = curr->next;
    }
    printf("\nReverse Linked List is: \n");
    curr = start;
    while (curr->next!=NULL)
    {
        curr = curr->next;
    }
    while (curr!=NULL)
    {
        printf("%d => ",curr->data);
        curr = curr->prev;
    }
    
}
void insert_at_beginning()
{
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    int info;
    printf("Enter Data: ");
    scanf("%d", &info);
    ptr->data = info;
    ptr->prev=NULL;
    ptr->next=start;
    start->prev=ptr;
    start=ptr;
}
void insert_at_middle()
{
    struct list *ptr, *temp, *temp2;
    ptr = (struct list *)malloc(sizeof(struct list));
    int position, info;
    printf("Enter Position: ");
    scanf("%d", &position);
    printf("Enter Data: ");
    scanf("%d", &info);
    ptr->data=info;
    temp = start;
    for(int i=0; i<position; i++)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    ptr->next = temp->next;
    temp->next = ptr;
    temp2->prev=ptr;
    ptr->prev=temp;
}
void insert_at_end()
{
    struct list *ptr, *temp;
    ptr = (struct list *)malloc(sizeof(struct list));
    int info;
    printf("Enter Data: ");
    scanf("%d", &info);
    ptr->data=info;
    temp = start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = ptr;
    ptr->prev=temp;
}
void delete_at_beginning()
{
    struct list *dlt;
    dlt=start;
    if(dlt!=NULL)
    {
        start = start->next;
        start->prev=NULL;
        free(dlt);
    }
}
void delete_at_middle()
{
    struct list *pre, *dlt, *post;
    int position;
    printf("Enter position: ");
    scanf("%d",&position);
    dlt=start;
    for(int i=0; i<position; i++)
    {
        pre=dlt;
        dlt=dlt->next;
    }
    if(dlt!=NULL)
    {
        post=dlt->next;
        pre->next=post;
        post->prev=pre;
        free(dlt);
    }
}
void delete_at_end()
{
    struct list *pre, *dlt;
    dlt=start;
    while(dlt->next!=NULL)
    {
        pre=dlt;
        dlt=dlt->next;
    }
    if(dlt!=NULL)
    {
        pre->next=NULL;
        free(dlt);
    }
}
int main()
{
    int input = 0;
    printf("*** Doubly Linked List ***");
    printf("\n");
    do{
        printf("Enter data (0 to exit): ");
        scanf("%d",&input);
        if(input!=0)
        {
            node = (struct list *)malloc(sizeof(struct list));
            node->data = input;
            node->prev = NULL;
            node->next = NULL;
            if(start==NULL)
            {
                start = node;
            }
            else
            {
                curr->next = node;
                node->prev = curr;
            }
            curr = node;
        }
    } while(input!=0); 
    display();
    int response = 0;
    do
    {
        printf("\nMENU");
        printf("\n1. Insert at Beginning.");
        printf("\n2. Insert at Middle.");
        printf("\n3. Insert at End.");
        printf("\n4. Delete at Beginning.");
        printf("\n5. Delete at Middle.");
        printf("\n6. Delete at End.");
        printf("\nEnter Response: ");
        scanf("%d", &response);
        switch (response)
        {
        case 1:
            insert_at_beginning();
            display();
            break;
        case 2:
            insert_at_middle();
            display();
            break;
        case 3:
            insert_at_end();
            display();
            break;
        case 4:
            delete_at_beginning();
            display();
            break;
        case 5:
            delete_at_middle();
            display();
            break;
        case 6:
            delete_at_end();
            display();
            break;
        default:
            response = 0;
            break;
        }
    } while (response!=0);
    
    return 0;
}