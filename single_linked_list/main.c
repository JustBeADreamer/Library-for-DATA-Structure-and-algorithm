#include "header.h"



int main(){ 
    List_t* head=NULL;
    head=insertEnd(head, Make_new_node(3));
    head=insertEnd(head, Make_new_node(2));
    head=insertEnd(head, Make_new_node(4));
    head=insertFirst(head, Make_new_node(1));
    head=DeleteEnd(head);
    head=DeleteFirst(head);
    head=Reverse_list(head);
    print_list(head);
}