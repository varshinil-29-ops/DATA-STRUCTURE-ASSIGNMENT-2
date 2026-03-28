#include <stdio.h>
#define MAX 6

int front = 0;
int rear = -1;
int size = 0;

int Queue[MAX];

void enqueue(int data){
    if(size == MAX){
        printf("Queue is full\n");
    }
    else{
        rear = (rear + 1) % MAX;
        Queue[rear] = data;
        size++;
    }
}

void dequeue(){
    if(size == 0){
        printf("Queue is empty\n");
    }
    else{
        printf("Deleting %d\n", Queue[front]);
        front = (front + 1) % MAX;
        size--;
    }
}

void peek(){
    if(size == 0){
        printf("Queue is empty\n");
    }
    else{
        printf("Peek element is %d\n", Queue[front]);
    }
}

void display(){
    if(size == 0){
        printf("Queue is empty\n");
    }
    else{
        int i = front;
        for(int count = 0; count < size; count++){
            printf("%d ", Queue[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main(){
    int choice = 1;

    while(choice == 1){
        int option;

        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option){
        case 1:
        {
            int dta;
            printf("Enter element: ");
            scanf("%d", &dta);
            enqueue(dta);
            break;
        }
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            choice = 0;
            break;
        default:
            printf("Invalid option!\n");
        }
    }

    return 0;
}