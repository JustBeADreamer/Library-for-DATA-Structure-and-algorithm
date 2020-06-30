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


void Initialize(Queue* Q){
    Plane* head;
    head=(Plane*)malloc(sizeof(Plane));
    head->next=NULL;
    Q->rear=head;
    Q->front=head;
}


int Is_empty(Queue* Q){
    if(Q->front==Q->rear)
        return 1;
    else 
        return 0;
}


void En_queue(int DATA, Queue* Q){
    Q->rear->next=(Plane*)malloc(sizeof(Plane));
    Q->rear=Q->rear->next;
    Q->rear->next=NULL;
    //Q->rear->DATA=DATA;
}

int* De_queue(int* DATA, Queue* Q){
    if(Is_empty(Q))
        printf("Queue is empty!!!\n");
    else{
        Plane* TEMP;
        TEMP=Q->front;
        Q->front=Q->front->next;
        //*DATA=Q->front->DATA;
        free(TEMP);
        return DATA;
    }
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




int main ()
{
    Queue Q[3];
    int i=0;
    FILE* fp;
    char name;
    int servingtime;



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
                while(fscanf(fp, "%s %s", name, &servingtime)!=EOF){
                    printf("%s %s", name, servingtime);
                }




                fclose(fp);
            }
            else if(choice == 2) {
                
            }
            else if(choice == 3) {

            }
            else if(choice == 4) {

            }
        } while(choice != 0);
    } while(choice < 0 && choice > 4);  

    return 0;  
}

