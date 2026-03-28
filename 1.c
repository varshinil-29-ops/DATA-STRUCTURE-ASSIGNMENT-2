#include <stdio.h>

char stack[20];
int top = -1;

void push(char data){
    if(top==(sizeof(stack)/sizeof(stack[0]))-1){
        printf("stack is full");
    }
    else{
        top++;
        stack[top] = data;
    }
}

char pop(){
    if(top == -1){
        printf("stack is empty");
    }
    else{
        char val = stack[top];
        top--;
        return val;
    }
}

int main(){
    char word[20];
    printf("enter a word: ");
    scanf("%s", word);
    char *ptr, x;
    ptr = word;

    while(*ptr != '\0'){
        push(*ptr);
        ptr++;
    }
    while(top > -1){
        printf("%c", pop());
    }
    return 0;
}