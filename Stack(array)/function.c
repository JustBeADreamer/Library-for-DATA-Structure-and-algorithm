#include "header.h"



int Is_empty(int top){
    return top==0;
}

int Is_full(int top){
    return top==MAX;
}

void Initialize(Stack_t* stack){
    stack->top=0;
}

void push(int DATA, Stack_t* stack){
    if(Is_full(stack->top)){
        printf("stack overflow");
    }
    else{
        stack->DATA[stack->top]=DATA;
        stack->top++;
    }
}


void pop(int *DATA, Stack_t* stack){
    if(!Is_empty(stack->top)){
        stack->top--;
        *DATA=stack->DATA[stack->top];
    }
    else
    {
        printf("Stack under flow");
    }
    
}

void Make_NULL(Stack_t* stack){
    int DATA;
    while(!Is_empty(stack->top)){
        pop(&DATA, stack);
    }
}

void print_stack(Stack_t* stack){
    int i=0;
    if(Is_empty(stack->top)){
        printf("Stack empty");
    }
    else{
        for(i=0;i<stack->top;i++){
            printf("%d\t", stack->DATA[i]);
        }
    }
}
