#ifndef Header_h
#define Header_h

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

typedef struct node_t{
    int DATA;
    struct node_t *left;;
    struct node_t *right;
}Node_t;



Node_t* Make_new_node(int DATA);

int Is_leaf(Node_t* Leaf);

Node_t* Insertion(Node_t* root, Node_t* New);



// TRANVERSAL
void preorder(Node_t* root);

void postorder(Node_t* root);

void Inorder_tranver(Node_t* root);



//finding functions

Node_t* search(Node_t* root, int key);

Node_t* find_Max(Node_t* root);

Node_t* find_Min(Node_t* root);


//DELETE FUNCTION
Node_t* Delete_Node(Node_t* root, int key);



// BREADTH FIRST SEARCH
int height(Node_t* node);

void printGivenLevel(Node_t* root, int level);

void printLevelOrder(Node_t* root);





#endif