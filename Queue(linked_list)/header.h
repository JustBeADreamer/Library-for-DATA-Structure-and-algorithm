#ifndef Header_h
#define Header_h



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//BASICALY QUEUE USING LIST IS A SINGLE LINKED LIST 
//HOWEVER ITS HAS 2 MORE POINTER TO POINT THE QUEUE (FRONT, REAR) WHICH IS IN QUEUE_T STRUCTURE

 
typedef struct node_t{
    int DATA;
    struct node_t* next;
}Node_t;


typedef struct queue_t{
    Node_t* front;
    Node_t* rear;
}Queue_t;


void Input_info(int* DATA);

void Initialize(Queue_t* Q);

int Is_empty(Queue_t* Q);

void En_queue(int DATA, Queue_t* Q);

int* De_queue(int* DATA, Queue_t* Q);

void Write_to_file(Queue_t* Q);

void Read_from_file(Queue_t* Q);

void Print(Queue_t* Q);

/*
int* Make_new_node();
*/


#endif