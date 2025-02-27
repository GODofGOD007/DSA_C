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
    printf("Double Circular Linked List before deletion from beginning: ");
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);

    temp = head;

    if (head == NULL)
    {
        printf("list is empty");
    }

    else if (head->next == head)
    {
        head = tail = NULL;
        free(temp);
    }

    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }

    free(temp);

    temp = head;
    printf("\nDouble Circular Linked List after deletion from beginning: ");
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);

    return 0;
}