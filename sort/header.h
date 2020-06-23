#include<stdio.h>
#include<string.h>


typedef struct {
    char name[20], email[20], phone[11];
} Phonebook;

typedef struct node {
    Phonebook data;
    struct node * next;
    struct node * prev;
} Node;

void bubble(int *, int, int);
void insertion(int *, int, int);
//Node * insertion(Node *);   //using linked list
//void insertion(Phonebook *, int, int);  //using array
void merge(int *, int, int, int);   //for mergeSort
void mergeSort(int *, int, int);
int partition(int *, int, int);  //for quick sort
void quickSort(int *, int, int);
void heapify(int *, int, int); //for heap sort
void heapSort(int *, int);