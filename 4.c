#include <stdio.h>
#define MAX 10

int Queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        Queue[rear] = data;
    }
}

void dequeue()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("deleting the document %d\n", Queue[front]);
        front++;
    }
}

void display()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

int  main(){
    int choice = 1;
    while (choice == 1)
    {
        int option;
        printf("1. Add document\n");
        printf("2. To delete a document\n");
        printf("3. To display the document\n");
        printf("4. Exit\n");
        printf("enter an option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            int dta;
            printf("add some document: ");
            scanf("%d", &dta);
            enqueue(dta);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            choice = 0;
            break;
        default:
            printf("Invalid option! Please choose between 1-4.\n");
        }
    }
    return 0;
}