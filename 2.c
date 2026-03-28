#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char data){
    if(top == (sizeof(stack)/sizeof(stack[0]))-1){
        printf("stack is full\n");
    }
    else{
        top++;
        stack[top] = data;
    }
}

char pop(){
    if(top == -1){
        printf("stack is empty\n");
        return '\0';
    }
    else{
        char val;
        val = stack[top];
        top--;
        return val;
    }
}

int main(){
    char expression[20];
    printf("enter an expression: ");
    scanf("%s", expression);

    char *e, x;
    e = expression;
    int count1 = 0;
    int count2 = 0;
    while(*e != '\0'){
        if(*e == '('){
            push(*e);
            count1++;
        }
        else if(isalnum(*e)){
            push(*e);
        }
        else if(*e == ')'){
            while((x=pop()) != '('){
                
            }
            if(x == '('){
                count2++;
            }
        }
        e++;
    }

    if(count1 == count2){
        printf("balanced exp");
    }
    else{
        printf("not a balanced exp");
    }
    return 0;
}