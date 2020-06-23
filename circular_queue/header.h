#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXLEN 5



struct Queue{
    int data[MAXLEN];
    int Front, Rear; 
};

struct Queue Q;

int Is_full(struct Queue *Q);

int Is_empty(struct Queue *Q);

void Make_Null(struct Queue *Q);

int En_Queue(int Data, struct Queue* Q);

int De_Queue(int *data, struct Queue* Q);

void Print_Queue(struct Queue Q);

