#include "header.h"


   

void Input_info(int* DATA){
    printf("input DATA: \n");
    scanf("%d", DATA);
}   
   
void Initialize(Queue_t* Q){
    Node_t* head;
    head=(Node_t*)malloc(sizeof(Node_t));
    head->next=NULL;
    Q->rear=head;
    Q->front=head;
}


int Is_empty(Queue_t* Q){
    if(Q->front==Q->rear)
        return 1;
    else 
        return 0;
}


void En_queue(int DATA, Queue_t* Q){
    Q->rear->next=(Node_t*)malloc(sizeof(Node_t));
    Q->rear=Q->rear->next;
    Q->rear->next=NULL;
    Q->rear->DATA=DATA;
}

int* De_queue(int* DATA, Queue_t* Q){
    if(Is_empty(Q))
        printf("Queue is empty!!!\n");
    else{
        Node_t* TEMP;
        TEMP=Q->front;
        Q->front=Q->front->next;
        *DATA=Q->front->DATA;
        free(TEMP);
        return DATA;
    }
}


void Write_to_file(Queue_t* Q){
    FILE* fp;
    
    int* DATA;
    DATA=(int*)malloc(sizeof(int));
    fp=fopen("Phonebook.dat", "wb");
    
    while(!Is_empty(Q)){
        De_queue(DATA, Q);
        fwrite(DATA, sizeof(int), 1, fp);
    }
    fclose(fp);
}


void Read_from_file(Queue_t* Q){
    int* DATA;
    DATA=(int*)malloc(sizeof(int));
    FILE *fp;

    fp=fopen("Phonebook.dat", "rb");
    if(fp!=NULL){

        fseek(fp, 0, SEEK_END);
        long fileSize = ftell(fp);
        rewind(fp);

        int numStruct = (int)(fileSize / sizeof(int));
        int loop;


        for (loop = 0; loop < numStruct; loop++){ 
            fread(DATA, sizeof(int), 1, fp);
            En_queue(*DATA, Q);
        }
    }
    else
    {
        printf("file empty");
    }
    
    fclose(fp);
}

void Print(Queue_t* Q){
    if(!Is_empty(Q)){
        while(!Is_empty(Q)){
            Q->front=Q->front->next;
            printf("%d\n", Q->front->DATA);
        }
    }
    else
    {
        printf("Queue empty");
    }
    
}


/*
//THIS FUNCTION IS FOR MORE COMMPLICATED STRUCTURE

int* Make_new_node(){
    int* DATA;
    DATA= (int*)malloc(sizeof(int)); 
    if(DATA==NULL)
        printf("Error for allocating memory!!!");
    else
        Input_info(DATA);
    return DATA;
}

*/

