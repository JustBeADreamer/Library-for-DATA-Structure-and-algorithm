#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define  MAX 5


typedef struct stack_t{
    int DATA[MAX];
    int top;
}Stack_t;




int Is_empty(int top);

int Is_full(int top);

void Initialize(Stack_t* stack);

void push(int DATA, Stack_t* stack);

void pop(int *DATA, Stack_t* stack);

void Make_NULL(Stack_t* stack);

void print_stack(Stack_t* stack);

#endif


