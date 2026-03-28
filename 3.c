#include <stdio.h>

int stack[50];
int top = -1;

void push(int data){
    top++;
    stack[top] = data;
}

int pop(){
    int val = stack[top];
    top--;
    return val;
}

int isempty(){
    return top == -1;
}

int main(){
    int size;
    printf("enter the size of the array: ");
    scanf("%d", &size);

    int arr[size], result[size];
    printf("enter the elements of the array: ");
    for(int i = 0; i<size; i++){
        scanf("%d", &arr[i]);
        result[i] = -1;
    }

    for(int i = 0; i<size; i++){
        while(!isempty() && arr[stack[top]] < arr[i]){
            result[pop()] = arr[i];
        }
        push(i);
    }

    for(int i = 0; i<size; i++){
        printf("%d -> %d\n", arr[i], result[i]);
    }
    return 0;
}