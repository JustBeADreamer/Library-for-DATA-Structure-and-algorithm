#include "header.h"


void main(){
    Node_t* root=NULL;
    root=Insertion(root, Make_new_node(5));
    root=Insertion(root, Make_new_node(3));
    root=Insertion(root, Make_new_node(7));
    root=Insertion(root, Make_new_node(2));
    root=Insertion(root, Make_new_node(4));
    root=Insertion(root, Make_new_node(6));
    root=Insertion(root, Make_new_node(8));
    root=Delete_Node(root, 5);
    Inorder_tranver(root);
    printLevelOrder(root);
    printf("\nroot is: %d", root->DATA);
}