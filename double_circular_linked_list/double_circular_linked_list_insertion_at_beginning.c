#include <stdio.h>
#include <stdlib.h>

int main()
{

    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    };

    struct node *head = NULL, *tail, *newnode, *temp;
    int choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
            tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("do you want to continue(0,1): ");
        scanf("%d", &choice);
    }

    temp = head;
    printf("Double Circular Linked List before insertion: ");
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nenter data to insert at beginning: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }

    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = newnode;
        tail->next = newnode;
        head = newnode;
    }

    temp = head;
    printf("Double Circular Linked List after insertion: ");
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);

    return 0;
}