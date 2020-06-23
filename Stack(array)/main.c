#include "header.h"


int main(){
    Stack_t* stack;
    int *DATA;
    DATA=(int*)malloc(sizeof(int));
    stack=(Stack_t*)malloc(sizeof(Stack_t));
    Initialize(stack);
    push(1, stack);
    push(2, stack);
    push(3, stack);
    push(4, stack);
    push(5, stack);
    push(6, stack);
    print_stack(stack);
    pop(DATA, stack);
    printf("\nPOPed: %d ", *DATA);
    print_stack(stack);
    Make_NULL(stack);
    print_stack(stack);
    return 0;
}




