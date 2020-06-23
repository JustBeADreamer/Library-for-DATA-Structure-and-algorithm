#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct list_t{
    int DATA;
    struct list_t* next;
}List_t;


//Some helpful functions

//check emptyness of the list

int IsEmpty(List_t* head);






//THESE FUNCTIONS ARE FOR INPUT NODE

//This function is for modifing the input UI and method
void Input_info(int* DATA);

//This is for creating new node
List_t *Make_new_node(int DATA);






//THESE FUNCTIONS ARE FOR INSERT MOTHOD: FIRST, END


//this is for input to the beginning of the list
List_t* insertFirst(List_t* head, List_t* New);


//this is for input to the end of the list
//have insertFirst function built in
//if the head is NULL => using the insert first function
List_t* insertEnd(List_t* head, List_t* New);







//THESE FUNCTIONS ARE FOR DELETE NODE, LIST


List_t* Delete_Node(List_t* head);          //for delete any Node at any position


List_t* DeleteFirst(List_t* head);         //for delete The first node of the list


List_t* DeleteEnd(List_t* head);           //for delete the last node of the list


List_t* Free_list(List_t* head);




//SOME INTERACTING FUNCTIONS WITH THE LIST

List_t* Reverse_list(List_t* head);

void print_list(List_t* head);





//READ, WRITE FUNCTIONS
List_t* Write_to_file(List_t* head);

List_t* Read_from_file(List_t* head);




#endif


