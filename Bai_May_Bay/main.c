#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>



typedef struct plane_t{
    char name[10];
    int servingtime;
    int waitingtime;
    int gate;
    struct plane_t* next;
}Plane;


typedef struct queue_t{
    struct plane_t* front;
    struct plane_t* rear;
    int totalwaitingtime;
}Queue;


int IsEmpty(Plane* head){
    return head==NULL;
}


Plane *Make_new_node(int gate, char name[10], int servingtime, Queue* Q){
    Plane* New;
    New=(Plane*)malloc(sizeof(Plane));
    if(New==NULL){
        printf("Error for allocating memory!!!");
        return NULL;
    }
    else
        strcpy(New->name, name);
        New->gate=gate+1;
        New->servingtime=servingtime;
        New->waitingtime=Q->totalwaitingtime;
        New->next=NULL;
    return New;
}



Plane* insertEnd(Plane* head, Plane* New){
    Plane* cur=head;

    if(IsEmpty(head)){
        New->next=head;
        head=New;
        return head;
    }
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=New;
    return head;
 
}









void Initialize(Queue* Q){
    Plane* head;
    head=(Plane*)malloc(sizeof(Plane));
    head->next=NULL;
    Q->rear=head;
    Q->front=head;
    Q->totalwaitingtime=0;
}


int Is_empty(Queue* Q){
    if(Q->front==Q->rear)
        return 1;
    else 
        return 0;
}




void Print(Queue* Q){
    if(!Is_empty(Q)){
        while(!Is_empty(Q)){
            Q->front=Q->front->next;
            //printf("%d\n", Q->front->DATA);
        }
    }
    else
    {
        printf("Queue empty");
    }
    
}


int Find_gate(Queue Q[]){
    int MIN=INT_MAX;
    int gate;
    int i=0;
    for(i=0;i<3;i++){
        if(Q[i].totalwaitingtime<MIN){
            MIN=Q[i].totalwaitingtime;
            gate=i;
        }
    }
    return gate;
}


void Input_queue(Queue* Q, int servingtime){
    Q->totalwaitingtime+=servingtime;
}


void print_list(Plane* head){
    Plane* cur;
    if(IsEmpty(head))
        printf("List_t empty!!!");

    else{
        cur=head;
        printf("Name\tGate\tServing time\t Waiting time\n");
        while(cur!=NULL){
            printf("%s\t%d\t%d\t\t%d\n", cur->name, cur->gate, cur->servingtime, cur->waitingtime);
            cur=cur->next;
            }
        }
}


Plane* Search(Plane* root, char name[10]){
    Plane* cur=NULL;
    cur=root;
    while (cur!=NULL)
    {
        if(strcmp(cur->name, name)==0)
            return cur;
        cur=cur->next;
    }
    return cur;
    
}


int main ()
{
    Queue Q[3];
    int i=0;
    FILE* fp;
    char name[10];
    int servingtime;
    int gate=-1;
    Queue* TEMP;
    Plane* head=NULL;
    Plane* cur=NULL;

    for(i=0;i<3;i++){
        Initialize(&Q[i]);
    }

    int choice;
    do {
        do {
            printf("\n\n\tMENU\n");
            printf("1. Print out information\n");
            printf("2. Print information of each plane\n");
            printf("3. Search flight number\n");
            printf("4. Counting time for taking luggages\n");
            printf("0. Quit\n");
            
            printf("Your choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                fp=fopen("gaterequest.txt", "r");
                while(fscanf(fp, "%s %d", name, &servingtime)!=EOF){
                    printf("%s %d\n", name, servingtime);
                    gate=Find_gate(Q);
                    TEMP=&Q[gate];
                    head=insertEnd(head, Make_new_node(gate, name, servingtime, &Q[gate]));
                    Input_queue(&Q[gate], servingtime);
                }
                fclose(fp);
            }
            else if(choice == 2) {
                print_list(head);
            }
            else if(choice == 3) {
                printf("Input flight number: \n");
                scanf("%s", name);
                cur=Search(head, name);
                if(cur==NULL)
                    printf("Flight doesnt exist.\n");
                else
                {   
                    printf("Name\tGate\tServingtime\twaitingtime\n");
                    printf("%s\t%d\t%d\t\t%d", cur->name, cur->gate, cur->servingtime, cur->waitingtime);
                }
                
            }
            else if(choice == 4) {

            }
        } while(choice != 0);
    } while(choice < 0 && choice > 4);  

    return 0;  
}

